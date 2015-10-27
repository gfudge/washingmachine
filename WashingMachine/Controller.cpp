#include "Controller.h"

namespace WashingMachine
{

	Controller::Controller()
	{
		/* Do not start the thread on construction, 
		let the child classes do that for us */
	}


	Controller::~Controller()
	{
		/* Safely kill the thread */
		stop_thread = true;
		if (the_thread.joinable()) {
			the_thread.join();
		}
	}

	void WashingMachine::Controller::Start()
	{
		the_thread = std::thread(&Controller::ThreadMain, this);
	}

	void Controller::ThreadMain()
	{
		while (!stop_thread) {
			/* Do something useful */
		}
	}

}