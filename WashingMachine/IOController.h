#pragma once
#include "Controller.h"
#include "Device.h"
#include "DeviceController.h"
#include "IOInterrupt.h"

/* Controllers */
#include "DisplayController.h"
#include "BuzzerController.h"
#include "MotorController.h"
#include "InputController.h"


/* Standard Libraries */
#include <thread>
#include <queue>
#include <vector>
#include <memory>
#include <exception>
#include <iostream>

namespace WashingMachine
{

	class IOController :
		public Controller
	{
	public:
		IOController();
		~IOController();

		/* Utility methods */
		int enumerateDevices();
		

		/* Interrupts */
		int interrupt(IOInterrupt &interrupt);
		int handleInterrupt(IOInterrupt &interrupt);

		/* Flag: true if initialised */
		bool isInitialised = false;

	private:

		std::vector<DeviceController*> deviceControllers;
		std::vector<Device> devices;

		/* Main thread routine, called after constructor */
		void ThreadMain();

		/* Owned Device Controllers */
		DeviceController* displayController;
		DeviceController* inputController;
		DeviceController* buzzerController;
		DeviceController* motorController;

		/* IOInterrupt FIFO buffer */
		std::queue<IOInterrupt> interruptBuffer;
		/* Low priority interrupts, handle when
		normal interruptBuffer is empty */
		std::queue<IOInterrupt> lowPriorityInterruptBuffer;
		
		/* Create/Kill controllers */
		int spawnControllers();
		int killControllers();
	};
}

