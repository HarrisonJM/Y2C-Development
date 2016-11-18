// TextFileCopy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int textFileCopy(string inFileName, string outFileName)
{
	
	ifstream inFile(inFileName, ios::in);
	ofstream outFile(outFileName, ios::out);

	if (!inFile.is_open())
	{
		cerr << "Could not open " << inFileName << " for reading" << endl;
		return 1;
	}

	if (!outFile.is_open())
	{
		cerr << "Could not open test.dat for writing" << endl;
		return 1;
	}

	getline(inFile, inFileName);

	while (!inFile.eof())
	{
		outFile << inFileName << endl;
		getline(inFile, inFileName);
	}	

	outFile.close();
	inFile.close();

	return 0;
}

int writeInputToFile()
{
	ofstream outFile("output.txt", ios::out);

	if (!outFile.is_open())
	{
		cerr << "Could not open test.dat for writing" << endl;
		return 1;
	}

	cout << "Enter some text (to quit, type end): " << endl;

	string input;
	getline(cin, input);

	while (input != "end")
	{
		outFile << input << endl;
		getline(cin, input);
	}

	outFile.close();

	return 0;
}

int readFromFile()
{
	string input;

	cout << "Text filename to read from: ";
	cin >> input;

	ifstream inFile(input, ios::in);

	if (!inFile.is_open())
	{
		cerr << "Could not open " << input << " for reading" << endl;
		return 1;
	}

	getline(inFile, input);

	while (!inFile.eof())
	{
		cout << input << endl;
		getline(inFile, input);
	}

	inFile.close();
	return 0;
}

int main()
{
	return textFileCopy("richardiii.txt", "copiedfile.txt");
}
