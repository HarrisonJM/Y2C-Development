#include "stdafx.h"

#pragma once

#include <string>

#include "userComment.h"

using namespace std;


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
