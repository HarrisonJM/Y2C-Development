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

void LinkedBunnies::insert(enum Bunny::SEX sex, int age, string name)
{
	Bunny* newItem = new Bunny(val, NULL);
	newItem->setNext(head); // head is the first item in the list
	head = newItem;
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

void LinkedBunnies::update(int currentVal, int newVal)
{
	Bunny* current = head;
	Bunny* previous = NULL;

	while (current != NULL)
	{
		if (current->getAge() == currentVal)
		{
			current->setAge(newVal);
			break;
		}

		previous = current;
		current = current->getNext();
	}

	return;
}
