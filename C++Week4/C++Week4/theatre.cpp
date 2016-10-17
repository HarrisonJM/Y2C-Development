#include "stdafx.h"

#pragma once

#include <string>
#include <vector>

#include "registerUser.h"
#include "theatre.h"

using namespace std;


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

