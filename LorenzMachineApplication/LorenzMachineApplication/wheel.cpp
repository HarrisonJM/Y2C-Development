#include "stdafx.h"
#include "wheel.h"
#include <string>
using std::string;

wheel::wheel(string pinSet, int pinSetting)
{
	for(int i=0;i<pinSet.length();i++)
	{
		pins.push_back(pinSet[i]);
	}
	this->pinSetting=this->pinSetting;
}

void wheel::rotate()
{
	if (++pinSetting > pins.size()) pinSetting = 0;
}

int wheel::getCurrentPin()
{
	return pins[pinSetting];
}