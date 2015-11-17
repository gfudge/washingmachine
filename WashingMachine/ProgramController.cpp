#include "ProgramController.h"


namespace WashingMachine
{

	ProgramController::ProgramController()
	{
	}


	ProgramController::~ProgramController()
	{
	}

	void ProgramController::next()
	{
		return this->instructionQueue.pop();
	}

}