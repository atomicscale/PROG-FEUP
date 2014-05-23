#include "Box.h"
#include "Utilities.h"

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
	// START reading movies
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
	// STOP reading movies

	// START reading channels
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
	// STOP reading channels

	// START reading programs to be recorded
	fin.open("data/toBeRecorded.txt");
	if (!fin) {
		std::cout << "Could not open toBeRecorded.txt" << std::endl;
		std::cin.get();
		exit(-1);
	}

	for (unsigned int i = 0; i < channels.size(); i++) {
		int numToBeRecorded;

		fin >> numToBeRecorded;
		for (int j = 0; j < numToBeRecorded; j++) {
			int duration, type, hour, min;
			std::string title;

			fin >> duration >> min >> hour >> type >> title;
			programsToBeRecorded.push_back(new Program(title, (ProgramType)type, 0, duration));
		}
	}
	fin.close();
	// STOP reading programs to be recorded

	// START reading programs recorded
	fin.open("data/recorded.txt");
	if (!fin) {
		std::cout << "Could not open recorded.txt" << std::endl;
		std::cin.get();
		exit(-1);
	}

	for (unsigned int i = 0; i < channels.size(); i++) {
		int numRecorded;

		fin >> numRecorded;
		for (int j = 0; j < numRecorded; j++) {
			int duration, type, min, hour;
			std::string title;

			fin >> duration >> min >> hour >> type >> title;
			recordedPrograms.push_back(new Program(title, (ProgramType)type, 1, duration));
		}
	}
	fin.close();
	// STOP reading programs recorded


}

void Box::saveData()
{

}

void Box::addToViewedMovies(Movie* movie) {
	viewedMovies.push_back(movie);
}

void Box::addToMovies(Movie* movie) {
	movies.push_back(movie);
}

bool Box::removeMovie(std::string name){

	for (std::vector<Movie*>::const_iterator itr = movies.begin(); itr != movies.end(); itr++)
	if (ToLower((*itr)->getTitle()).compare(ToLower(name)) == 0) {
		std::cout << (*itr)->getTitle() << " Successfully Deleted";
		movies.erase(itr);
		return true;
	}
	return false;
}

std::vector<Movie*> Box::getMovies()
{
	return movies;
}

std::vector<Program*> Box::getProgramsToBeRecorded()
{
	return programsToBeRecorded;
}

std::vector<Movie*> Box::getViewedMovies()
{
	return viewedMovies;
}

std::vector<Channel*> Box::getChannels()
{
	return channels;
}

template <class T>
bool writeVector(const std::string& fileName, const std::vector<T>& vector) {
	std::ofstream out(fileName);

	if (!out.is_open())
		return false;

	out << vector.size() << std::endl;

	for (std::vector<T>::const_iterator it = vector.begin(); it != vector.end(); it++)
		out << *it << std::endl;

	out.close();

	return true;
}

bool Box::saveToFile() const
{
	return
		writeVector("data/movies.txt", movies) &&
		writeVector("data/viewedMovies.txt", viewedMovies);
}

bool Box::removeChannel(std::string name)
{
	for (std::vector<Channel*>::const_iterator itr = channels.begin(); itr != channels.end(); itr++)
	if (ToLower((*itr)->getName()).compare(ToLower(name)) == 0) {
		std::cout << (*itr)->getName() << " Successfully Deleted";
		channels.erase(itr);
		return true;
	}
	return false;
}

void Box::addToChannels(Channel* name)
{
	channels.push_back(name);
}

std::vector<Program*> Box::getRecordedPrograms()
{
	return recordedPrograms;
}
