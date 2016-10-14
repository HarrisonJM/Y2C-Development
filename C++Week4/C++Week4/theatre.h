#ifndef THEATRE_H
#define THEATRE_H

#include "stdafx.h"

#pragma once

#include "registerUser.h"
#include <string>
#include <vector>

using namespace std;

class Theatre
{
private:
	string address;
	vector<RegisterUser> users;

public:
	Theatre::Theatre(string givenAddress)
	{
		address = givenAddress;
	}

	RegisterUser Theatre::RegisterAUser(string name, string address)
	{
		RegisterUser tempUser(name, address);
		users.push_back(tempUser);

		return tempUser;
	}
};


//#include "stdafx.h"
//
//#pragma once
//
//#include "registerUser.h"
//#include <string>
//#include <vector>
//
//using namespace std;
//
//class Theatre
//{
//private:
//	string address;
//	vector<RegisterUser> users;	
//
//public:
//	Theatre(string address);
//	RegisterUser RegisterAUser(string, string);
//};

#endif
