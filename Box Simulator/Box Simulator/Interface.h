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
	void listChannels();
};

