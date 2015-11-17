#include "ProgramController.h"


namespace WashingMachine
{

	ProgramController::ProgramController()
	{
	}


	ProgramController::~ProgramController()
	{
	}

	Instruction* ProgramController::next()
	{
		if (instructionQueue.empty())
		{
			return nullptr;
		}
		else
		{
			return this->instructionQueue.pop();
		}
	}

	void populateQueue()
	{
		// Copy all of the instructions into the instructionQueue
	}

}