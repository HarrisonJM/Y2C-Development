// OldFriends.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vehicle.h"

int main()
{
	Vehicle v;
	Car c("Audi:A4");  // convert function assumes
	v.convert(c);      // this : delimited format

	string make = findMake(v); // find the make of the vehicle

	system("pause");
}

// a function to find the make of a given vehicle
string findMake(Vehicle& v)
{
	return v.make;
}