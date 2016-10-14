#ifndef USERRATING_H
#define USERRATING_H

#include "stdafx.h"

#pragma once

class UserRating
{
private:
	int rating;

public:
	UserRating::UserRating(int vote)
	{
		rating = vote;
	}
};


//#include "stdafx.h"
//
//#pragma once
//
//class UserRating
//{
//private:
//	int rating;
//
//public:
//	UserRating(int vote);
//};

#endif
