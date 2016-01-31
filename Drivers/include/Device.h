#pragma once
#include "main.h"


namespace WashingMachine
{

	class Device
	{
		public:
			Device(uint16_t *port);
			virtual ~Device();
			int read();
			int write(uint16_t data);
		
		private:
			uint16_t *port;
	};

}
