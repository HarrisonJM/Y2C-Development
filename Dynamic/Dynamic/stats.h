#ifndef STATS_H
#define STATS_H

class stats
{
private:
	int* scores;  // you will need to make a change to this line
	int scoreCount;

public:
	stats();
	// you will need to implement a destructor to "tidy up"
	void getScores();
	float findAverage();
};

#endif