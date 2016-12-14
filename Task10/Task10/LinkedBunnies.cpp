#include "LinkedBunnies.h"

LinkedBunnies::LinkedBunnies()
{
	head = NULL;
}

LinkedBunnies::~LinkedBunnies()
{
	Bunny* current = head;
	Bunny* temp;

	while (current != NULL)
	{
		temp = current->getNext();
		delete current;
		current = temp;
	}
}

void LinkedBunnies::insert(int age)
{
	//Bunny(int age, Bunny *nextBunny)
	Bunny* newBunny = new Bunny(age, NULL);
	newBunny->setNext(head); // head is the first item in the list
	head = newBunny;
}

bool LinkedBunnies::remove(int val)
{
	Bunny* current = head;
	Bunny* previous = NULL;

	while (current != NULL)
	{
		if (current->getAge() == val)
		{
			previous->setNext(current->getNext());
			delete current;
			return true;
		}
		previous = current;
		current = current->getNext();
	}
	return false;
}

void LinkedBunnies::updateAge(int currentVal, int newVal) //updates first bunny found
{
	Bunny* current = head;

	while (current != NULL)
	{
		if (current->getAge() == currentVal)
		{
			current->setAge(newVal);
			break;
		}

		current = current->getNext();
	}

	return;
}

void LinkedBunnies::updateAllAge(int currentVal, int newVal) //updates all bunnies of that age
{
	Bunny* current = head;

	while (current != NULL)
	{
		if (current->getAge() == currentVal)
		{
			current->setAge(newVal);
		}

		current = current->getNext();
	}

	return;
}

void LinkedBunnies::AgeBunnies()
{
	Bunny* current = head;

	while (current != NULL)
	{
		current->setAge(current->getAge() + 1);

		current = current->getNext();
	}
}
