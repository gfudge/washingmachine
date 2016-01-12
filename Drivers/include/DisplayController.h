#pragma once
#include "DeviceController.h"

namespace WashingMachine
{

	class DisplayController :
		public DeviceController
	{
	public:
		DisplayController();
		~DisplayController();
		int writeDisplay();
		int readDisplay();
	};

}
