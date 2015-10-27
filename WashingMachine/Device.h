#pragma once

namespace WashingMachine
{

	class Device
	{
	public:
		Device();
		virtual ~Device();
		int open();
		int close();
		int read();
		int write();
	};

}
