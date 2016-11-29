#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListItem.h"

#define NULL nullptr

class linkedList
{
private:
	listItem* head;

public:
	linkedList();
	~linkedList();

	void insert(int);
	bool remove(int);
	void update(int currentVal, int newVal);
};

#endif