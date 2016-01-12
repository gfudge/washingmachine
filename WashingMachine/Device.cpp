#include "Device.h"


namespace WashingMachine
{

	Device::Device(enum mode mode, unsigned int pin, unsigned int speed)
	{
		this->mode = mode;
		this->pin = pin;
		this->speed = speed;
		if (this->open() == 0) {
			this->valid = true;
		}
		
	}


	Device::~Device()
	{
		this->close();
	}

	int Device::open()
	{
		if (base != nullptr) {
			
			switch (this->mode) {
			case INPUT:

			case OUTPUT:
				/* Set mode */
				base->MODER = (device_ptr)0x55555555;
				/* Set Speed */
				base->OSPEEDR = (device_ptr)0xFFFFFFFF;
				/* Set pullup,etc */
				base->PUPDR = (device_ptr)0xAAAAAAAA;
				return 0;

			default:
				return -1;
			}
		}
		else {
			return -1;
		}

	}
	
	int Device::close()
	{
		this->valid = false;
	}

	int Device::read()
	{
		if (this->valid) {
			device_data tmp_data = base->ODR;
		}
	}

	int Device::write(device_data data)
	{
		if (this->valid) {

		}
	}

	bool Device::valid()
	{
		if (!isInit) {
			return false;
		}
		else if (base == nullptr)
		{
			return false;
		}
		else {
			return true;
		}
	}
}