#include "stdafx.h"
#include "wheelGroup.h"

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
	for(int i=0;i<wheels.size()-1;i++)
	{
		wheels[i].rotate();
	}
}

int wheelGroup::getCurrentPins()
{
	int result = 0;
	
	for(int i=0;i<wheels.size();i++)
	{
		result <<= 1;
		result &= wheels[i].getCurrentPin();
	}

	return result;
}