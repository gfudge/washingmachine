#include "TimingController.h"


namespace WashingMachine
{

	TimingController::TimingController()
	{
	}


	TimingController::~TimingController()
	{
	}

	unsigned int TimingController::getCurrentTime()
	{
		/* Return the time now */
		return 0;
	}

	/* This allows ANY object to set a timer*/
	template<typename T>
	int TimingController::addTimer(T* owner, unsigned int expiryTime)
	{
		/* Create new timer object and push it to the list */
		Timer* newTimer(owner, expiryTime);
		this->timers.push_back(newTimer);
		return 0;
	}

	int TimingController::removeTimer()
	{
		return 0;
	}

	int TimingController::checkTimers()
	{
		for (auto &timer : this->timers) {
			if (timer.remainingTime() <= 0) {
				/* Timer expired */
				this->completeTimer(timer);
			}
		}
		return 0;
	}

	template<typename T>
	int TimingController::completeTimer(Timer timer)
	{
		auto owner = timer->getOwner():
		return 0;
	}

}