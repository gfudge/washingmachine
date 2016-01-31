#include "BuzzerController.h"
#include "hal.h"

namespace WashingMachine
{

	BuzzerController::BuzzerController()
	{
		Device *pBuzzer;
		pBuzzer = new Device((uint16_t* ) DEV_BUZZER_ODR);

		this->devices.push_back(pBuzzer);
	}

	void BuzzerController::on()
	{
		this->devices[0]->write(DEV_BUZZER_BITMASK);
		this->state = 1;
	}

	void BuzzerController::off()
	{
		this->devices[0]->write(DEV_BUZZER_BITMASK);
		this->state = 0;
	}

}
