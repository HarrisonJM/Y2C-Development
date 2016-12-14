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
	int bunnyGenderIndex;
	int bunnyColourIndex;
	int bunnyNameIndex;
	int bunnyAge; //0 -> 10
	Bunny* nextBunny = NULL;

	const string colour[4] = { "White", "Brown", "Black", "Spotted" };
	const string sex[2] = { "Male", "Female" };
	const string name[10] = { "Bugs", "Rabbit", "Alfred", "Dave", "Susan", "Maria", "Fluffykins", "Ginger", "Hobnob", "Stewart" };

public:
	Bunny::Bunny(int age, Bunny *nextBunny);

	void genBunnyGender();
	string getBunnyGender();

	void genColour();
	string getColour();

	void genName();
	string getName();

	void setAge(int newValue);
	int getAge();

	void setNext(Bunny* listItem);
	Bunny* getNext();
	
};

#endif