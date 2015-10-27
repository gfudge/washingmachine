#pragma once
#include "Controller.h"
#include "Timer.h"

/* Standard Libraries */
#include <vector>

namespace WashingMachine
{

	class TimingController :
		public Controller
	{
	public:
		TimingController();
		~TimingController();

		/* Get current time helper method */
		unsigned int getCurrentTime();

		/* Generic add timer method for setting custom callbacks */
		template<typename T>
		int addTimer(T * owner, unsigned int expiryTime);

		int removeTimer();
		int checkTimers();
	private:
		size_t maximumTimers = 10;
		std::vector<Timer> timers;
		int completeTimer(Timer timer);
	};

}
