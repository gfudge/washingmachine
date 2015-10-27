#include "Timer.h"


namespace WashingMachine
{
	/* Basic Constructor */
	/* Args: Pointer to owner class, time until expiry (TODO: decide unit) */
	template<typename T>
	Timer<T>::Timer(T * owner, unsigned int expireTime)
	{
		this->owner = owner;
		this->expireTime = expireTime;
	}

	/* Destructor */
	template<typename T>
	Timer<T>::~Timer()
	{
		/* If owner class pointer not null, nullify it */
		if (this->owner != nullptr) {
			this->owner = nullptr;
		}
	}

	template<typename T>
	long long int Timer<T>::remainingTime()
	{
		/* Return time remaining (negative if expired) */
		/* TODO: Get actual time */
		long unsigned int currentTime = 0;
		/* Result is number of ticks till timer */
		return (long unsigned int) expireTime - currentTime;
	}

	/* May not need this; only require that owner has Callback method */
	template<typename T, class T2>
	void Timer<T>::addHandler(T* owner)
	{
		/* Add the owner to something for later */
		this->owner = owner;
	}

	/* Allow access to private owner field only if not null */
	template<typename T>
	T * Timer<T>::getOwner()
	{
		if (this->owner != nullptr) {
			return this->owner;
		}
		else {
			return nullptr;
		}
	}
}
