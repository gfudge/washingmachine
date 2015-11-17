#pragma once

#include <string>

namespace WashingMachine
{
	enum instructionType
	{
		ITEM1,
		ITEM2,
		ITEM3,
		ITEM4
	};

	class Instruction
	{
	public:
		Instruction(instructionType instruction, unsigned int value);
		~Instruction();

	private:
		instructionType instruction;
		unsigned int value;
	};
}
