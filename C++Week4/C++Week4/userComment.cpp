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
