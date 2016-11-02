#include "stdafx.h"
#include "wheel.h"
#include <string>
using std::string;

wheel::wheel(string pinSet, int pinSettingpar)
{
	pinSetting = pinSettingpar;

	for (int i = 0; i < pinSet.length(); i++)
	{
		int number = pinSet[i] - '0';
		pins.push_back(number);
	}
}

void wheel::rotate()
{
	if (++pinSetting > pins.size()) pinSetting = 0;
}

int wheel::getCurrentPin()
{
	return pins[pinSetting];
}