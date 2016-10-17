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
	Movie
	(
		string title, 
		int year, 
		string desc, 
		string genre 
	);

	UserRating AddMovieRating(int);
	UserComment AddComment(string);

};

#endif