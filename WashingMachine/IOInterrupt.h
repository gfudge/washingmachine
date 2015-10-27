#pragma once
#include "Interrupt.h"

namespace WashingMachine
{

	class IOInterrupt : public Interrupt
	{
	public:
		IOInterrupt(enum priority priority, enum device device);
		~IOInterrupt();
		enum device device;

	};

}
