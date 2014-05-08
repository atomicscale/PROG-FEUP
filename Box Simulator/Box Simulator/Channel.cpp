#include "Channel.h"


Channel::Channel(std::string name)
{
	this->name = name;
}


Channel::~Channel()
{
}

std::string Channel::getName(){
	return name;
}