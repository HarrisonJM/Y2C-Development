#include "stdafx.h"
#include "wheel.h"
#include <string>
using std::string;

wheel::wheel(string pinSet, int pinSettingPar)
{
	for (int i = 0; i < pinSet.length(); i++)
	{
		pins.push_back(pinSet[i] - '0'); //BUG FIX 2
	}

	pinSetting = pinSettingPar; //BUG FIX 1
}

void wheel::rotate()
{
	if (++pinSetting > pins.size())
		pinSetting = 0;
}

int wheel::getCurrentPin()
{
	return pins[pinSetting];
}