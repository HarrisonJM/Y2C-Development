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

	void Theatre::RegisterAUser(string name, string address)
	{
		RegisterUser tempUser(name, address);
		users.push_back(tempUser);
	}
};
