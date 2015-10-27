#pragma once
#include "Device.h"
#include "IOInterrupt.h"

/* Standard Libraries */
#include <vector>

namespace WashingMachine
{

	class DeviceController
	{
	public:
		DeviceController();
		virtual ~DeviceController();
		int numberOfDevices();
		std::vector<Device*> listOfDevices();

		/* Interrupt Routines */
		int interrupt(IOInterrupt & interrupt);
	private:
		std::vector<Device*> devices;
		std::vector<Interrupt> interruptBuffer;
	};
}

