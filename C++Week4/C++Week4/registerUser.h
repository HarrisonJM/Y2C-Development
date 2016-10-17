#ifndef REGISTERUSER_H
#define REGISTERUSER_H

#include "stdafx.h"

#pragma once

#include <string>
#include <vector>
#include "movie.h"
#include "userData.h"

using namespace std;

class RegisterUser
{
	private:
		string email;
		string password;
		vector<Movie> movies;
		vector<UserData> userDatas;

	public:
		RegisterUser(string email, string password);
		Movie AddMovie(string, int, string, string);
		UserData AddUserData(string, string, string);
};

#endif