#include "ListItem.h"

Bunny::Bunny(SEX bunnyGender, int age, Bunny* nextItem, Bunny *nextBunny)
{
}

void Bunny::setNext(Bunny* listItem)
{
	this->nextBunny = listItem;
}

Bunny* Bunny::getNext()
{
	return this->nextBunny;
}

int Bunny::getAge()
{
	return this->age;
}

void Bunny::setAge(int newVal)
{
	this->age = newVal;
}