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
	RegisterUser::RegisterUser(string givenEmail, string givenPassword)
	{
		email = givenEmail;
		password = givenPassword;
	}

	void RegisterUser::AddMovie(string title, int year, string desc, string genre)
	{
		Movie tempMovie(title, year, desc, genre);
		movies.push_back(tempMovie);
	}

	void RegisterUser::AddUserData(string name, string address, string creditCard)
	{
		UserData tempUD(name, address, creditCard);
		userDatas.push_back(tempUD);
	}
};
