#pragma once
#include <string>
#include <vector>

#include "Program.h"

class Channel
{
private:
	std:: string name;
	std::vector <Program*> programs;
public:
	Channel();
	~Channel();
};

