#include "stdafx.h"
#include "Vehicle.h"

void Vehicle::convert(Car c)
{
// code to split the car details 
	// into make and model
	int i = c.details.find(":");
	make = c.details.substr(0,i);
	model = c.details.substr(i+1,c.details.length());
}