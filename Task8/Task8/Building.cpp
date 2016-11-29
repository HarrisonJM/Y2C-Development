#include "Building.h"

Building::Building(int numpep, int numflo, int avLigPFlo, int avCompPFlo, int PKWHUs)
{
	numberOfPeople = numpep;
}

Building::Building(int numpep)
{
	numberOfPeople = numpep;
}

Building::Building()
{
	
}

Building::~Building()
{
}

void Building::calculatePKWHUse()
{
	//pretend this uses all information to find the averagePKWH usage
}

double Building::getCarbonFootPrint()
{
	double footprint;
	double averageCarbonPP = 9.66;

	footprint = averageCarbonPP * numberOfPeople; //peryear

	return footprint;
}
