#include "DeviceController.h"


namespace WashingMachine
{

	DeviceController::DeviceController()
	{
	}


	DeviceController::~DeviceController()
	{
		for (unsigned int i; i <= this->getDeviceCount(); i++)
			delete(this->devices[i]);
	}

	int DeviceController::getDeviceCount()
	{
		return this->devices.size();
	}
/*
	int DeviceController::interrupt(IOInterrupt & interrupt)
	{
		this->interruptBuffer.push_back(interrupt);
		return 0;
	}
*/
}