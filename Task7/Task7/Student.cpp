#include "Student.h"

Student::Student()
{
	//default constrcutor
}

Student::Student(string namePar, int studentIDPar)
{
	name = namePar;
	studentID = studentIDPar;
}

string Student::getName()
{
	return name;
}

int Student::getID()
{
	return studentID;
}

string Student::getDegClass()
{
	return DegClass;
}

int Student::getMarks()
{
	return marks;
}

void Student::setDegClass(string DegPar)
{
	DegClass = DegPar;
}

void Student::setMarks(int markPar)
{
	marks = markPar;
}
