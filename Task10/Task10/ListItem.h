#ifndef LISTITEM_H
#define LISTITEM_H

#define NULL nullptr

class listItem
{
private:
	int dataValue;
	listItem* nextListItem = NULL;

public:
	listItem(int val, listItem* nextItem);
	void setNext(listItem* listItem);
	listItem* getNext();
	int getValue();
	void setValue(int newValue);
};

#endif