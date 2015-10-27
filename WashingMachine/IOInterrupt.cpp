#include "IOInterrupt.h"

namespace WashingMachine
{

	IOInterrupt::IOInterrupt(enum priority priority, enum device device)
	{
		this->priority = priority;
		this->device = device;
		this->destination = destination::PROGRAM;
		this->type = type::IO;
	}

	IOInterrupt::~IOInterrupt()
	{
	}

}