#pragma once
#include <string>

#include "Date.h"

enum ProgramType {
	NEWS,
	SPORTS,
	ENTERTAINMENT,
	LIFE_STYLE
};

class Program
{
private:
	std::string name;
	ProgramType type;
	bool recorded;
	int duration;
	Date exhibitionDate;

public:
	Program();
	~Program();
};

