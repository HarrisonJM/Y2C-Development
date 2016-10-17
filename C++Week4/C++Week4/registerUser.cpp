#include "stdafx.h"

#pragma once

#include <string>
#include <vector>
#include "movie.h"
#include "userData.h"
#include "registerUser.h"

using namespace std;

	RegisterUser::RegisterUser(string givenEmail, string givenPassword)
	{
		email = givenEmail;
		password = givenPassword;
	}

	Movie RegisterUser::AddMovie(string title, int year, string desc, string genre)
	{
		Movie tempMovie(title, year, desc, genre);
		movies.push_back(tempMovie);

		return tempMovie;
	}

	UserData RegisterUser::AddUserData(string name, string address, string creditCard)
	{
		UserData tempUD(name, address, creditCard);
		userDatas.push_back(tempUD);

		return tempUD;
	}

