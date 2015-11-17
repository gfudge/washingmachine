#include "Instruction.h"

namespace WashingMachine
{

	Instruction::Instruction(WashingMachine::instructionType instruction, unsigned int value)
	{
		this->instruction = instruction;
		this->value = value;
	}


	Instruction::~Instruction()
	{
	}

}