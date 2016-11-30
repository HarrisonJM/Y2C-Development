#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListItem.h"

class LinkedBunnies
{
private:
	Bunny* head;

public:
	LinkedBunnies();
	~LinkedBunnies();

	void LinkedBunnies::insert(enum Bunny::SEX sex, int age, string name);
	bool remove(int);
	void update(int currentVal, int newVal);
};

#endif