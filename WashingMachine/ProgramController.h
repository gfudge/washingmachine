#pragma once
#include "Controller.h"
#include "Instruction.h"

#include <queue>

namespace WashingMachine
{
	class ProgramController :
		public Controller
	{
	public:
		ProgramController();
		~ProgramController();
		void next();
	private:
		std::queue<Instruction> instructionQueue;
	};

}
