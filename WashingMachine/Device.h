#pragma once

#include <exception>

namespace WashingMachine
{

	typedef device_ptr(uint32_t);
	typedef device_data(uint16_t);
	enum mode {INPUT, OUTPUT};


	class Device
	{
	public:
		Device(enum mode, unsigned int pin, unsigned int speed);
		virtual ~Device();
		int open();
		int close();
		int read();
		int write(device_data data);

	private:
		bool isInit = false;
		volatile device_ptr *base;
		device_data data;
		enum mode mode;
		unsigned int pin;
		unsigned int speed = 2;
		bool valid();
	};

}
