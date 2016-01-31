#pragma once
#include "DeviceController.h"


namespace WashingMachine
{

	class BuzzerController :
		public DeviceController
	{
	public:
		BuzzerController();

		void on();
		void off();

		bool getState() { return this->state; };

	private:
		bool state;

	};

}
