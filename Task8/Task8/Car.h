#pragma once

#include "CarbonFootprint.h"

class Car : public CarbonFootprint
{
private:
	int MPG; //MilesPerGallon
	int averageNumberOfPeopleInCar;
	int averageMilesTravelled;

	//pretend I did something with this

public:

	Car();
	~Car();

	virtual double getCarbonFootPrint();
};
