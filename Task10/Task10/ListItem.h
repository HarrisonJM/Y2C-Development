#ifndef LISTITEM_H
#define LISTITEM_H

#include <string>

using namespace std;

class Bunny
{

	enum SEX {
		MALE, 
		FEMALE
	};

	enum COLOUR {
		WHITE,
		BROWN,
		BLACK,
		SPOTTED
	};

	friend class LinkedBunnies;

private:
	SEX bunnyGender;
	int age; //0 -> 10
	string name;

	Bunny* nextBunny = NULL;

public:
	Bunny(SEX bunnyGender, int age, Bunny* nextItem, Bunny *nextBunny);
	void setNext(Bunny* listItem);
	Bunny* getNext();

	int getAge();
	void setAge(int newValue);
};

#endif