#pragma once
#include "DeviceController.h"


namespace WashingMachine
{

	class MotorController :
		public DeviceController
	{
	public:
		MotorController();
		~MotorController();
	};


}