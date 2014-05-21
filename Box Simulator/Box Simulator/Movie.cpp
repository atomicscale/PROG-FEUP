#include "Movie.h"

#include <string>

Movie::Movie(std::string title, double cost)
{
	this->title = title;
	this->cost = cost;
	rentedTimes = 0;
}


Movie::~Movie()
{
}

std::string Movie::getTitle() const
{
	return title;
}

void Movie::incrementRentedTimes()
{
	rentedTimes++;
}

std::ostream& operator<<(std::ostream& out, const Movie& movie)
{
	out << movie.getTitle() << " | " << movie.getRentedTimes() << " | " << movie.getCost();

	return out;
}
