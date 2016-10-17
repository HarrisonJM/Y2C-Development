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
	UserComment(string comment);

	void IncrementThumbsUp();
	void IncrementTimesRead();
};

#endif