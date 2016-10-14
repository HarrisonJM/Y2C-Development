#ifndef MOVIE_H
#define MOVIE_H

#include "stdafx.h"

#pragma once

#include <string>
#include <vector>

#include "userRating.h"
#include "userComment.h"

using namespace std;

class Movie
{
private:
	string title;
	int year;
	string desc;
	string genre;
	vector<UserRating> ratings;
	vector<UserComment> comments;

public:
	Movie::Movie(string givenTitle, int givenYear, string givenDesc, string givenGenre)
	{
		title = givenTitle;
		year = givenYear;
		desc = givenDesc;
		genre = givenGenre;
	}

	UserRating Movie::AddMovieRating(int rating)
	{
		UserRating tempUR(rating);
		ratings.push_back(tempUR);

		return tempUR;
	}

	UserComment Movie::AddComment(string comment)
	{
		UserComment tempComm(comment);
		comments.push_back(tempComm);

		return tempComm;
	}

};

//#include "stdafx.h"
//
//#pragma once
//
//#include <string>
//#include <vector>
//
//#include "userRating.h"
//#include "userComment.h"
//
//using namespace std;
//
//class Movie
//{
//private:
//	string title;
//	int year;
//	string desc;
//	string genre;
//	vector<UserRating> ratings;
//	vector<UserComment> comments;
//
//public:
//	Movie
//	(
//		string title, 
//		int year, 
//		string desc, 
//		string genre 
//	);
//
//	UserRating AddMovieRating(int);
//	UserComment AddComment(string);
//
//};


#endif