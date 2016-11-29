#pragma once

#include "CarbonFootprint.h"

class Bicycle : public CarbonFootprint
{
private:
	double initialFoorPrint = 240.404; //kilos
	double KCycled; //kilomets cycled

public:

	Bicycle();
	Bicycle(int cycled);


	~Bicycle();

	virtual double getCarbonFootPrint();
};