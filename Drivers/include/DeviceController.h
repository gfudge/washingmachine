#pragma once
#include "Device.h"
//#include "IOInterrupt.h"

/* Standard Libraries */
#include <vector>

namespace WashingMachine
{

	class DeviceController
	{
	public:
		DeviceController();
		virtual ~DeviceController();
		int getDeviceCount();
	
		/* Interrupt Routines */
	//	int interrupt(IOInterrupt & interrupt);
	protected:
		std::vector<Device*> devices;
		//std::vector<Interrupt> interruptBuffer;
	};
}

