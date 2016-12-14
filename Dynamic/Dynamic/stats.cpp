#include "stdafx.h"
#include "stats.h"
#include <iostream>
using namespace std;

stats::stats()
{

}

void stats::getScores()
{
	// ask user how many scores to input
	cout << "How many scores?";
	cin >> scoreCount;

	// collect each score and store it
	int score;
	for (int i = 0; i < scoreCount; i++)
	{
		cout << "What is score " << i + 1 << "? ";
		cin >> score;
		scores[i] = score;
	}
}

float stats::findAverage()
{
	// iterate through scores to find total
	float total = 0.0f;
	for (int i = 0; i < scoreCount; i++)
	{
		total += scores[i];
	}

	// return the average score
	return (total / scoreCount);
}