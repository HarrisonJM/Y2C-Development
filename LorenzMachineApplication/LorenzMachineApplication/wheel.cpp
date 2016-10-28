#include "stdafx.h"
#include "wheel.h"

#include <sstream>

wheel::wheel(string pinSet, int pinSetting)
{
	// implementation code should be added here
	int number;

	std::stringstream tempss(pinSet);

	while (tempss >> number)
	{
		pins.push_back(number);
	}
}

void wheel::rotate()
{
	// implementation code should be added here
}

int wheel::getCurrentPin()
{
	// implementation code should be added here
	// you should also change the return statement
	// where appropriate

	return 0;
}
