#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Bunny.h"

class LinkedBunnies
{
private:
	Bunny* head;

public:
	LinkedBunnies();
	~LinkedBunnies();

	void LinkedBunnies::insert(int age);
	bool remove(int);

	void updateAge(int currentVal, int newVal);
	void updateAllAge(int currentVal, int newVal);
	void AgeBunnies();
};

#endif