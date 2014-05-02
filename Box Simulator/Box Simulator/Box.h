#pragma once

#include <string>
#include <vector>

#include "Channel.h"
#include "Movie.h"
#include "Program.h"

class Box
{
private:
	std::string ownerPassword;
	std::vector<Channel*> channels;
	std::vector<Movie*> movies;
	std::vector<Movie*> viewedMovies;
	std::vector<Program*> recordedPrograms;
	std::vector<Program*> programsToBeRecorded;
	double spentMoney;
	
public:
	Box();
	~Box();
};

