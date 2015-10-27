#pragma once

/* Standard Library */
#include <thread>
#include <vector>

namespace WashingMachine
{
	/* Parent class that allows for safe thread
	handling in child classes */
	class Controller
	{
	public:
		Controller() : the_thread() {}
		virtual ~Controller();
		/* Do not start the thread here */
		void Start();

	/* Protected because child classes need
	the awesome threading stuff (thats the 
	entire point of this class) */
	protected:
		std::thread the_thread;
		virtual void ThreadMain();
		bool stop_thread = false;
	};	


}