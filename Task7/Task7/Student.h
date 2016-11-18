#pragma once

#include <string>

using namespace std;

class Student
{
private:
	string name;
	int studentID;
	string DegClass;
	int marks;
public:
	Student();
	Student(string namePar, int studentIDPar);

	string getName();
	int getID();
	string getDegClass();
	int getMarks();

	void setDegClass(string DegPar);
	void setMarks(int markPar);

};
