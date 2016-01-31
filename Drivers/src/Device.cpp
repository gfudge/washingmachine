#include "Device.h"


namespace WashingMachine
{

	Device::Device(uint16_t *port)
	{
		this->port = port;
	}

	Device::~Device()
	{
	}

	int Device::read()
	{
		return 0;
	}
	
	int Device::write(uint16_t data)
	{
		*(this->port) ^= data;
		return 0;
	}
		
}