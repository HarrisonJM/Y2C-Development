#include "stdafx.h"

#pragma once

#include <string>
#include <vector>

#include "userRating.h"
#include "userComment.h"
#include "movie.h"

using namespace std;

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