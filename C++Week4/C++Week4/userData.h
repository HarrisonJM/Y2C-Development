#ifndef USERDATA_H
#define USERDATA_H

#include "stdafx.h"

#pragma once

#include <string>

using namespace std;

class UserData
{
private:
	string name;
	string address;
	string creditCard;

public:
	UserData(string name, string address, string creditCard);
};

#endif
