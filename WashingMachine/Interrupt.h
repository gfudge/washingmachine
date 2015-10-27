#pragma once

namespace WashingMachine
{

	enum priority {HIGH, NORMAL, LOW};
	enum destination {PROGRAM, TIMER, DISPLAY, INPUT, MOTOR, BUZZER};
	enum type {TIMER, IO, PROGRAM};
	enum device {DISPLAY, INPUT, MOTOR, BUZZER};

	class Interrupt
	{
	public:
		Interrupt() = default;
		Interrupt(enum priority priority, enum destination destination);
		virtual ~Interrupt();
		enum priority priority;
		enum destination destination;
		enum type type;
	};


}