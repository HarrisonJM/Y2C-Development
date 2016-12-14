#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "ListItem.h"

class linkedList
{
private:
	listItem* head;

public:
	linkedList();
	~linkedList();

	void insert(int);
	bool remove(int);
	bool update(int currentVal, int newVal);
};

#endif