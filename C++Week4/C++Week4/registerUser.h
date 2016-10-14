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
};


//#include "stdafx.h"
//
//#pragma once
//
//#include <string>
//#include <vector>
//#include "movie.h"
//#include "userData.h"
//
//using namespace std;
//
//class RegisterUser
//{
//	private:
//		string email;
//		string password;
//		vector<Movie> movies;
//		vector<UserData> userDatas;
//
//	public:
//		RegisterUser(string email, string password);
//		Movie AddMovie(string, int, string, string);
//		UserData AddUserData(string, string, string);
//};

#endif