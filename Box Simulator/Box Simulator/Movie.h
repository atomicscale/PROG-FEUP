#pragma once
#include <string>

class Movie
{
private:
	std::string title;
	double cost;
	long rentedTimes;

public:
	Movie(std::string title, double cost);
	~Movie();

	std::string getTitle();
};

