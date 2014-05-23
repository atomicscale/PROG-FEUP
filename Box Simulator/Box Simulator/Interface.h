#pragma once

#include "Box.h"

class Interface
{
private:
	Box* box;
public:
	Interface();
	~Interface();

	void start();
	void listMovies();
	void listUnviewedMovies();
	void listViewedMovies();
	void listChannels();
	void listProgramsToBeRecorded();
	void listRecordedPrograms();
	void Settings();
	void rentMovies();
	void manageMovies();
	void manageChannels();
	bool savePassword(std::string password);
};

