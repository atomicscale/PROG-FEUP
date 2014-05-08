#include "Interface.h"
#include <iostream>

Interface::Interface()
{
	box = new Box();
}


Interface::~Interface()
{
	delete(box);
}

void clearStdInAndPressEnterToContinue() {
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "Press Enter to continue...";
	std::cin.get();
}

void Interface::start()
{
	box->loadData();

	bool done;
	do {
		done = false;

		std::cout << "-----------------" << std::endl;
		std::cout << "- Box Simulator -" << std::endl;
		std::cout << "-----------------" << std::endl;
		std::cout << std::endl;
		std::cout << "1. List Movies" << std::endl;
		std::cout << "2. List Channels" << std::endl;
		std::cout << "3. Settings" << std::endl;
		std::cout << "4. Exit" << std::endl;

		int input;
		std::cin >> input;

		if (1 <= input && input <= 4) {
			switch (input) {
			case 1:
				listMovies();
				clearStdInAndPressEnterToContinue();
				break;
			case 2:
				listChannels();
				clearStdInAndPressEnterToContinue();
				break;
			case 3:
				break;
			case 4:
				std::cout << std::endl;
				std::cout << "Quitting program." << std::endl;
				done = true;
				break;
			}
		}
		else
			clearStdInAndPressEnterToContinue();
	} while (!done);
}

void Interface::listMovies()
{
	std::vector<Movie*> movies = box->getMovies();

	std::cout << std::endl;
	std::cout << "Movies" << std::endl;
	std::cout << "------" << std::endl;
	for (unsigned int i = 0; i < movies.size(); i++)
		std::cout << movies[i]->getTitle() << std::endl;
	std::cout << std::endl;
}

void Interface::listChannels()
{
	std::vector<Channel*> channel = box->getChannels();

	std::cout << std::endl;
	std::cout << "Channels" << std::endl;
	std::cout << "------" << std::endl;
	for (unsigned int i = 0; i < channel.size(); i++)
		std::cout << channel[i]->getName() << std::endl;
	std::cout << std::endl;
}
