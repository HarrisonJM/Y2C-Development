#include <string>

#include "Bunny.h"


Bunny::Bunny(int age, Bunny *nextBunny)
{
	this->bunnyAge = age;

	genBunnyGender();
	genColour();
	genName();
}


void Bunny::genBunnyGender()
{
	int randNum = rand() % 2;

	this->bunnyGenderIndex = randNum;
}

string Bunny::getBunnyGender()
{
	return sex[bunnyGenderIndex];
}


void Bunny::setAge( int age)
{
		this->bunnyAge = age;
}

int Bunny::getAge()
{
	return this->bunnyAge;
}


void Bunny::genColour()
{
	int randNum = rand() % 4;

	this->bunnyColourIndex = randNum;
}

string Bunny::getColour()
{
	return this->colour[bunnyColourIndex];
}


void Bunny::genName()
{
	int randNum = rand() % 4;

	this->bunnyColourIndex = randNum;

}

string Bunny::getName()
{
	return name[bunnyNameIndex];
}


void Bunny::setNext(Bunny* listItem)
{
	this->nextBunny = listItem;
}

Bunny* Bunny::getNext()
{
	return this->nextBunny;
}