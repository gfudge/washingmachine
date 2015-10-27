#pragma once

#include "DeviceController.h"
#include "ProgramController.h"

/* Standard Library */
#include <functional>

namespace WashingMachine
{
	enum type {DEVICE, PROGRAM};

	class Timer
	{
	public:
		template<typename T>
		Timer(T* owner, unsigned int expireTime);

		~Timer();
		/* Long Long so can store +/- time */
		long long int remainingTime();

		/* Templated add handler method - type defined by calling class */
		template<typename T, class T2>
		void addHandler(T* owner);

		template<typename T>
		T* getOwner();

	private:
		long unsigned int startTime;
		long unsigned int expireTime;
		enum type timerType;

		T* owner;
	};
}

