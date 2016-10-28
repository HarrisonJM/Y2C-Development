#include "stdafx.h"
#include "wheel.h"

#include <sstream>

wheel::wheel(string pinSet, int pinSettingPar)
{
	//Fills wheel with pin settings
	int number;
	pinSetting = pinSettingPar;

	for (int i = 0; i < pinSet.length(); ++i)
	{
		number = pinSet[i] - '0';
		pins.push_back(number);
	}
}

void wheel::rotate() //increments pin index
{
	if (pinSetting > pins.size() - 1)
	{
		pinSetting = 0;
	}
	else
	{
		pinSetting++;
	}
}


int wheel::getCurrentPin() //returns pin at pin setting
{
	return pins[pinSetting];
}
