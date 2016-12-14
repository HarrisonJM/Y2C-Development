#include "stdafx.h"
#include "LinkedList.h"

linkedList::linkedList()
{
	head = NULL;
}

linkedList::~linkedList()
{
	listItem* current = head;
	listItem* temp;

	while (current != NULL)
	{
		temp = current->getNext();
		delete current;
		current = temp;
	}
}

void linkedList::insert(int val)
{
	listItem* newItem = new listItem(val, NULL);
	newItem->setNext(head); // head is the first item in the list
	head = newItem;
}

bool linkedList::remove(int val)
{
	listItem* current = head;
	listItem* previous = NULL;

	while (current != NULL)
	{
		if (current->getValue() == val)
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

bool linkedList::update(int currentVal, int newVal)
{
	listItem* updatedItem = new listItem(newVal, NULL);

	
}