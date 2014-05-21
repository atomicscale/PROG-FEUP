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

		if (1 <= input && input <= 7) {
			switch (input) {
			case 1:
				//rentMovies();
				//clearStdInAndPressEnterToContinue();
			case 2:
				listMovies();
				clearStdInAndPressEnterToContinue();
				break;
			case 3:
				listChannels();
				clearStdInAndPressEnterToContinue();
				break;
			case 4:
				//listPrograms();
				//clearStdInAndPressEnterToContinue();
				break;
			case 5:
				//listViewedMovies();
				//clearStdInAndPressEnterToContinue();
				break;
			case 6:
				Settings();
				break;
			case 7:
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

void Interface::Settings()
{
	std::string password;
	std::string novapassword;
	std::cout << std::endl;
	std::cout << "Settings" << std::endl;
	std::cout << "------" << std::endl;
	std::cout << "Enter Password" << std::endl;
	std::cin >> password;
	std::cout << std::endl;
	novapassword == password;
	bool done;
	if (password == "password")
	{
		do{
			done = false;

			

			std::cout << "Settings" << std::endl;
			std::cout << "------" << std::endl;
			std::cout << "1. Change Password" << std::endl;
			std::cout << "2. Manage Movies" << std::endl;
			std::cout << "3. Manage Channels" << std::endl;
			std::cout << "4. Manage Programs" << std::endl;
			std::cout << "5. Exit Settings" << std::endl;

			int input;
			std::cin >> input;

			if (1 <= input && input <= 5) {
				switch (input) {
				case 1:
					std::cout << "Introduce new password" << std::endl;
					std::cin >> novapassword;
					std::cout << "Password alterada" << std::endl;
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					std::cout << std::endl;
					std::cout << "Quitting Settings." << std::endl;
					done = true;
					break;
				}
			}
			else
				clearStdInAndPressEnterToContinue();


		} while (!done);
		
	}
	else
	{
		std::cout << "Wrong Password" << std::endl;
		clearStdInAndPressEnterToContinue();
	};

	password == novapassword;

}