#include <deque>
#include <map>
#include <iostream>

#include "Student.h"

using namespace std;

Student AddNewStudent(int ID);

//map<int, Student> RemoveStudent(int ID, map<int, Student> t);

int PrintAllStudents(map<int, Student> Cohort);
void UserQuit();


int main( void )
{
	int selection, ID;
	map<int, Student> Cohort;

	while (1)
	{
		cout << "Student Cohort Program" << endl;
		cout << "1.........Add New Student to cohort" << endl;
		cout << "2.........Remove Student from cohort" << endl;
		cout << "3.........Print all Students in cohort" << endl;
		cout << "4.........Delete entire Cohort" << endl;
		cout << "5.........Quit" << endl;

		cout << "Select option and hit return: ";

		cin >> selection;

		switch (selection)
		{
		case 1:
			cout << "Please enter StudentID (number): ";
			cin >> ID; //student ID entered first to use as a map key
			Cohort[ID] = AddNewStudent(ID);
			break;
		case 2:
			cout << "Please enter StudentID (number): ";
			cin >> ID;
			Cohort.erase(ID);
			break;
		case 3: PrintAllStudents(Cohort);
			break;
		case 4: Cohort.erase(Cohort.begin(), Cohort.end());
			break;
		case 5: UserQuit();
			break;
		default: cout << "invalid option try again" << endl;
			break;
		}
	}
	
	return 0;
}

Student AddNewStudent(int ID)
{
	string string;
	int n;
	cout << "Please Enter Students name:";
	cin >> string;

	Student student(string, ID);

	cout << "Enter Students Degree Class (leave blank if none): ";
	cin >> string;
	student.setDegClass(string);

	cout << "Enter Students average marks (leave blank if none): ";
	cin >> n;
	student.setMarks(n);

	return student;
}

int PrintAllStudents(map<int, Student> Cohort)
{
	for (map<int, Student>::iterator it = Cohort.begin(); it != Cohort.end(); ++it)
	{
		Student stemp;
		stemp = it->second; //This was done due to a lack of understanding of how the syntax can be used

		cout << "Student name: " << stemp.getName() << endl;
		cout << "Student ID: " << stemp.getID() << endl;
		cout << "Student Marks: " << stemp.getMarks() << endl;
		cout << "Student Degree Class: " << stemp.getDegClass() << endl;
	}

	return 0;
}

void UserQuit()
{
	char yn;

	cout << "Are you sure you want to quit? (y or n): " << endl;
	cin >> yn;

	switch (yn)
	{
	case 'y':
	case 'Y':
		exit(0);
		break;
	case 'n':
	case 'N':
		break;
	default:
		cout << "Invalid option. Returning to menu..." << endl;
	}

}
