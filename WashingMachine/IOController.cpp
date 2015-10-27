#include "IOController.h"


namespace WashingMachine
{

	IOController::IOController()
	{
		this->spawnControllers();
		isInitialised = true;
		/* Wait until the controllers exist before starting,
		this prevents a potential race condition (and not 
		needing to use atomics for everything) */
		this->Start();
	}


	IOController::~IOController()
	{
		/* Signal to stop the thread before killing stuff */
		stop_thread = true;
		/* OK, now kill stuff */
		this->killControllers();
		isInitialised = false;
		/* */
		if (the_thread.joinable()) {
			the_thread.join();
		}
	}

	/* TODO: make this decent and do something useful */
	/* Returns number of devices enumerated */
	int IOController::enumerateDevices()
	{
		int totalDevices = 0;
		for (auto &deviceController : deviceControllers) {
			if (deviceController->numberOfDevices() >= 0) {
				totalDevices += deviceController->numberOfDevices();
			}
			
		}
		return 0;
	}

	int IOController::spawnControllers()
	{
		/* TODO: Implement these controllers */
		this->displayController		= new DisplayController();
		this->inputController		= new InputController();
		this->buzzerController		= new BuzzerController();
		this->motorController		= new MotorController();
		deviceControllers.push_back(displayController);
		deviceControllers.push_back(inputController);
		deviceControllers.push_back(buzzerController);
		deviceControllers.push_back(motorController);
		return 0;
	}

	/* Destroy owned controller classes */
	int IOController::killControllers()
	{
		delete this->displayController;
		delete this->inputController;
		delete this->buzzerController;
		delete this->motorController;
		return 0;
	}

	/* Routine called to prioritise interrupts */
	int IOController::interrupt(IOInterrupt & interrupt)
	{
		switch (interrupt.priority) {
		case HIGH: 
			/* This is important so we will handle it now */
			this->handleInterrupt(interrupt);
			break;

		case NORMAL:
			/* Normal so push it to the back of the queue */
			this->interruptBuffer.push(interrupt);
			break;

		case LOW:
			/* This is lowest priority so it has its own queue */
			this->lowPriorityInterruptBuffer.push(interrupt);
			break;
		}
		return 0;
	}

	/* Handle the interrupt - Call by value instead?*/
	/* Args: Value of interrupt object */
	/* Returns: integer: Positive good, negative bad. Zero = meh. */
	int IOController::handleInterrupt(IOInterrupt & interrupt)
	{
		/* Choose who gets the interrupt */
		switch (interrupt.device) {
			/* Call the respective interrupt method of the controller object */
		case DISPLAY: 
			this->displayController->interrupt(interrupt);
			return 1;
		case INPUT:
			this->inputController->interrupt(interrupt);
			return 2;
		case MOTOR:
			this->motorController->interrupt(interrupt);
			return 3;
		case BUZZER:
			this->buzzerController->interrupt(interrupt);
			return 4;
		default:
			//throw std::runtime_error("IOInterrupt: Error: Invalid interrupt.device field");
			/* This did not work, and the caller should deal with it. */
			return -1;
		}
		return 0;
	}


	/* This routine will continuously handle interrupts. ONLY when the 
	normal priority interrupts are handled will the routine handle
	low priority interrupts, one at a time, whilst checking for 
	normal priority interrupts. */
	void IOController::ThreadMain()
	{
		/* Do this forever in a thread */
		while (!stop_thread) {
			try
			{
				/* While the normal priority interruptBuffer is populated, handle those */
				while (!interruptBuffer.empty()) {
					/* Get next interrupt */
					IOInterrupt nextInterrupt = this->interruptBuffer.front();
					/* Check the handleInterrupt succeeded */
					if (this->handleInterrupt(nextInterrupt) < 0) {
						/* Failiure, throw an exception */
						throw std::runtime_error("IOInterrupt: Error: mishandled normal priority interrupt, skipping...");
					}
					/* Realistically, we have to keep going, ignore it and move on */
					this->interruptBuffer.pop();
				}
				
				/* Check the low interrupt priority queue and handle ONE interrupt */
				if (!lowPriorityInterruptBuffer.empty()) {
					/* Handle the first interrupt */
					IOInterrupt nextLowPriorityInterrupt = this->lowPriorityInterruptBuffer.front();
					/* Check the handleInterrupt succeeded */
					if (this->handleInterrupt(nextLowPriorityInterrupt) < 0) {
						throw std::runtime_error("IOInterrupt: Error: mishandled low priority interrupt, skipping...");
					}
					/* Again, going to have to bin this interrupt (otherwise, what's the point of interrupts?) */
					this->interruptBuffer.pop();
				}

			}
			catch (const std::exception& e)
			{
				/* Print error to COUT (maybe log, later) and keep going */
				std::cout << e.what() << std::endl;
				continue;
			}
		}
	}

}
