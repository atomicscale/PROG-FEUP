#include "Interface.h"

#include <iostream>
#include <fstream>
#include "Utilities.h"

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
	std::cout << std::endl;
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
		std::cout << "Movies" << std::endl;
		std::cout << "1. Unviewed Movies" << std::endl;
		std::cout << "2. Viewed Movies" << std::endl;
		std::cout << "3. Rent Movies" << std::endl;
		std::cout << std::endl;
		std::cout << "Channels and Programs" << std::endl;
		std::cout << "4. List Channels" << std::endl;
		std::cout << "5. Programs To Be Recorded" << std::endl;
		std::cout << "6. Recorded Programs" << std::endl;
		std::cout << std::endl;
		std::cout << "Others" << std::endl;
		std::cout << "7. Settings" << std::endl;
		std::cout << "8. Exit" << std::endl;
		std::cout << std::endl;

		int input;
		std::cout << "Choose an option: ";
		std::cin >> input;

		if (1 <= input && input <= 8) {
			switch (input) {
			case 1:
				listUnviewedMovies();
				clearStdInAndPressEnterToContinue();
				break;
			case 2:
				listViewedMovies();
				clearStdInAndPressEnterToContinue();
				break;
			case 3:
				rentMovies();
				clearStdInAndPressEnterToContinue();
				break;
			case 4:
				//listChannels();
				clearStdInAndPressEnterToContinue();
				break;
			case 5:
				//listProgramsToBeRecorded();
				clearStdInAndPressEnterToContinue();
				break;
			case 6:
				//listRecordedPrograms();
				clearStdInAndPressEnterToContinue();
				break;
			case 7:
				Settings();
				break;
			case 8:
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

void Interface::listUnviewedMovies()
{
	std::vector<Movie*> movies = box->getMovies();

	std::cout << std::endl;
	std::cout << "Unviewed Movies" << std::endl;
	std::cout << "---------------" << std::endl;
	for (unsigned int i = 0; i < movies.size(); i++)
	if (movies[i]->getRentedTimes() == 0)
		std::cout << movies[i]->getTitle() << std::endl;
	std::cout << std::endl;
}

void Interface::listViewedMovies(){
	std::vector<Movie*> movies = box->getViewedMovies();

	std::cout << std::endl;
	std::cout << "Viewed Movies" << std::endl;
	std::cout << "-------------" << std::endl;
	for (unsigned int i = 0; i < movies.size(); i++)
		std::cout << movies[i]->getTitle() << "\t\t Times rented: " << movies[i]->getRentedTimes() << std::endl;
	std::cout << std::endl;
}

void Interface::rentMovies(){
	listMovies();

	std::string title;
	std::cout << "Choose a Movie: ";
	std::cin >> title;

	// search for title
	bool found = false;
	for (unsigned int i = 0; i < box->getMovies().size(); i++) {
		// if title found
		if (ToLower(box->getMovies()[i]->getTitle()).compare(ToLower(title)) == 0) {
			Movie* movie = box->getMovies()[i];
			found = true;

			// increment rented times
			movie->incrementRentedTimes();

			// if rented times WAS 0, add movie to viewed movies
			if (movie->getRentedTimes() - 1 == 0)
				box->addToViewedMovies(movie);

			std::cout << "\"" << movie->getTitle() << "\" successfully rented." << std::endl;
			break;
		}
	}

	// if not found, do nothing
	if (!found)
		std::cout << "Movie not found." << std::endl;
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
	std::cout << std::endl;
	std::cout << "Settings" << std::endl;
	std::cout << "------" << std::endl;
	std::cout << "Enter Password" << std::endl;
	std::cin >> password;
	std::cout << std::endl;
	bool done;

	std::ifstream fin;
	fin.open("data/generalInformation.txt");
	if (!fin) {
		std::cout << "Could not open generalInformation.txt" << std::endl;
		std::cin.get();
		exit(-1);
	}

	std::string ownerpassword;
	fin >> ownerpassword;
	if (password == ownerpassword)
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
					std::cin >> password;
					savePassword(password);
					std::cout << "Password alterada" << std::endl;
					clearStdInAndPressEnterToContinue();
					break;
				case 2:
					manageMovies();
					clearStdInAndPressEnterToContinue();
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					std::cout << std::endl;
					std::cout << "Quitting Settings." << std::endl;
					done = true;
					clearStdInAndPressEnterToContinue();
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
}

bool Interface::savePassword(std::string password){
	std::ofstream file;
	file.open("data/generalInformation.txt");
	if (!file.is_open()) {
		std::cout << "Could not open generalInformation.txt" << std::endl;
		std::cin.get();
		return false;
	}

	file << password << std::endl;
	file << box->getMovies().size();
	file.close();
	return true;
}
void Interface::manageMovies()
{
	//Read Movies
	listMovies();
	std::string title;
	std::cout << "Choose a Movie: ";
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	getline(std::cin,title);
	//if movie is in the list, delete it
	if (!box->removeMovie(title)){
		box->addToMovies(new Movie(title, 10));
		std::cout << title << " Successfully Added";
	}
	else{
		std::cout << title << " Successfully Deleted";
	}

}