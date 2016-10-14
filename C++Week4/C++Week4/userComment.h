#ifndef USERCOMMENT_H
#define USERCOMMENT_H

#include "stdafx.h"

#pragma once

#include <string>

using namespace std;

class UserComment
{
private:
	string comment;
	int timesRead;
	int thumbsUp;

public:
	UserComment::UserComment(string sentComment)
	{
		comment = sentComment;
		timesRead = 0;
		thumbsUp = 0;
	}

	void UserComment::IncrementThumbsUp()
	{
		thumbsUp++;
	}

	void UserComment::IncrementTimesRead()
	{
		timesRead++;
	}
};


//#include "stdafx.h"
//
//#pragma once
//
//#include <string>
//
//using namespace std;
//
//class UserComment
//{
//private:
//	string comment;
//	int timesRead;
//	int thumbsUp;
//
//public:
//	UserComment(string comment)
//	{
//		int timesRead = 0;
//		int thumbsUp = 0;
//	}
//
//	void IncrementThumbsUp();
//	void IncrementTimesRead();
//};

#endif