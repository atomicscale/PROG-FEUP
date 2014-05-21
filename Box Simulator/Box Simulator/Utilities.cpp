#include "Utilities.h"

#include <ctype.h>

std::string ToLower(std::string str)
{
	for (unsigned int i = 0; i < str.length(); ++i)
		str[i] = tolower(str[i]);

	return str;
}
