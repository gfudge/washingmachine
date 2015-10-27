#include "DeviceController.h"


namespace WashingMachine
{

	DeviceController::DeviceController()
	{
	}


	DeviceController::~DeviceController()
	{
	}

	int DeviceController::numberOfDevices()
	{
		return this->devices.size();
	}

	std::vector<Device*> DeviceController::listOfDevices()
	{
		if (this->numberOfDevices() > 0) {
			return (std::vector<Device*>)devices;
		}
		else {
			return std::vector<Device*>();
		}
	}

	int DeviceController::interrupt(IOInterrupt & interrupt)
	{
		this->interruptBuffer.push_back(interrupt);
		return 0;
	}

}