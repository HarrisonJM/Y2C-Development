#include "stdafx.h"

#pragma once

#include <string>

#include "userData.h"

using namespace std;


	UserData::UserData(string givenName, string givenAddress, string givenCreditCard)
	{
		name = givenName;
		address = givenAddress;
		creditCard = givenCreditCard;
	}

