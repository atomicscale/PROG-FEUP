#pragma once

#include <string>
#include <vector>
#include <ostream>

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

	bool saveToFile() const;

	void loadData();
	void saveData();

	void addToViewedMovies(Movie* movie);
	void addToMovies(Movie* movie);
	void addToChannels(Channel* name);
	bool removeMovie(std::string name);
	bool removeChannel(std::string name);

	std::vector<Movie*> getMovies();
	std::vector<Movie*> getViewedMovies();
	std::vector<Channel*> getChannels();
	std::vector<Program*> getProgramsToBeRecorded();
	std::vector<Program*> getRecordedPrograms();
};

