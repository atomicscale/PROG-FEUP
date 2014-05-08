#include "Box.h"

#include <iostream>
#include <string>
#include <fstream>

Box::Box()
{
	channels.clear();
	movies.clear();
	viewedMovies.clear();
	recordedPrograms.clear();
	programsToBeRecorded.clear();
	spentMoney = 0;
}


Box::~Box()
{
}

void Box::loadData()
{
	std::ifstream fin;
	fin.open("data/movies.txt");
	if (!fin) {
		std::cout << "Could not open movies.txt" << std::endl;
		std::cin.get();
		exit(-1);
	}

	int numMovies;
	fin >> numMovies;
	for (int i = 0; i < numMovies; i++) {
		std::string movieTitle;
		fin >> movieTitle;

		movies.push_back(new Movie(movieTitle, 10));
	}
		fin.close();

		fin.open("data/channels.txt");
		if (!fin) {
			std::cout << "Could not open channels.txt" << std::endl;
			std::cin.get();
			exit(-1);
		}
		int  numChannels;
		fin >> numChannels;
		for (int i = 0; i < numChannels; i++) {
			std::string channelName;
			fin >> channelName;

			channels.push_back(new Channel(channelName));
	}
		fin.close();
}

void Box::saveData()
{

}

std::vector<Movie*> Box::getMovies()
{
	return movies;
}

std::vector<Channel*> Box::getChannels()
{
	return channels;
}