#include "ListItem.h"

listItem::listItem(int val, listItem* nextItem)
{
	setValue(val);
	setNext(nextItem);
}

void listItem::setNext(listItem* listItem)
{
	this->nextListItem = listItem;
}

listItem* listItem::getNext()
{
	return this->nextListItem;
}

int listItem::getValue()
{
	return this->dataValue;
}

void listItem::setValue(int newVal)
{
	this->dataValue = newVal;
}