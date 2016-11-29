#include "Car.h"

class Vehicle
{
public:
	void convert(Car c);
	friend string Vehicle::findMake(Vehicle& v);

private:
	string make, model;
};
