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
	void Settings();
	void rentMovies();
	void manageMovies();
};

