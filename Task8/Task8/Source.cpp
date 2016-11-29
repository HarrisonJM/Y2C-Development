//ENTRY POINT!

#include "Bicycle.h"
#include "Building.h"
#include "Car.h"

#include <string>
#include <iostream>
#include <vector>

int main()
{
	std::vector<CarbonFootprint*> footprints;
	Car car;
	Bicycle bike(692);
	Building building(160);


	footprints.push_back(&building);
	footprints.push_back(&car);
	footprints.push_back(&bike);

	for (int i = 0; i < 3; ++i)
	{
		std::cout << "CarbonFootprint of ";
		
		switch (i)
		{
		case 0: std::cout << "building is: ";
			break;
		case 1: std::cout << "Car is: ";
			break;
		case 2: std::cout << "Bike is: ";
			break;
		}

		std::cout << footprints.at(i)->getCarbonFootPrint() << std::endl;

	}

	system("pause");

	return 0;
}