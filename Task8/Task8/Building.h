#pragma once

#include "CarbonFootprint.h"

class Building : public CarbonFootprint
{
private:
	int numberOfPeople;
	int numberOfFloors;
	int averageLightsPerFloor;
	int averageComputersPerFloor;
	int PKWHUsage; //per kilowatt hour

public:

	Building(int numpep, int numflo, int avLigPFlo, int avCompPFlo, int PKWHUs);

	Building(int numpep);

	Building();

	~Building();

	void calculatePKWHUse();

	virtual double getCarbonFootPrint();

};
