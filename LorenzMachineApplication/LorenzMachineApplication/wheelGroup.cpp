#include "stdafx.h"
#include "wheelGroup.h"

#include <sstream>
#include <iostream>

wheelGroup::wheelGroup(wheel wheel1, wheel wheel2, wheel wheel3, wheel wheel4, wheel wheel5)
{
	wheels.push_back(wheel1);
	wheels.push_back(wheel2);
	wheels.push_back(wheel3);
	wheels.push_back(wheel4);
	wheels.push_back(wheel5);
}

void wheelGroup::rotate()
{
	for (int i = 0; i < 5; ++i)
	{
		wheels[i].rotate();
	}
}

int wheelGroup::getCurrentPins()
{
	int pins[5];
	int ret = 0, num, rem, base = 1;
	stringstream strstr;

	for (int i = 0; i < 5; ++i)
	{
		pins[i] = wheels[i].getCurrentPin();
	}

	for (unsigned i = 0; i < sizeof pins / sizeof pins[0]; ++i)
	{
		strstr << pins[i];
	}

	strstr >> num;

	while (num > 0)
	{
		rem = num % 10;
		ret = ret + rem * base;
		num = num / 10;
		base = base * 2;
	}

	return ret;
}
