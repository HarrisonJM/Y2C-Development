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

	void Movie::AddMovieRating(int rating)
	{
		UserRating tempUR(rating);
		ratings.push_back(tempUR);
	}

	void Movie::AddComment(string comment)
	{
		UserComment tempComm(comment);
		comments.push_back(tempComm);
	}

};