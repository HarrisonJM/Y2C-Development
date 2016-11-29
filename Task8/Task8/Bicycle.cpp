#include "Bicycle.h"

Bicycle::Bicycle()
{
}

Bicycle::Bicycle(int cycled)
{
	KCycled = cycled;
}

Bicycle::~Bicycle()
{
}

double Bicycle::getCarbonFootPrint()
{
	//initialFootPrint = 240.404Kg
	//one must cycle 692.018KM to cancel out a bikes footprint

	//0.347kg/km

	double kmpkg = 0.347;

	double footprint;
	double currentYield;

	currentYield = KCycled * kmpkg;
	footprint = initialFoorPrint - currentYield; //total, negative value indicates carbon prevention

	return footprint;
}
