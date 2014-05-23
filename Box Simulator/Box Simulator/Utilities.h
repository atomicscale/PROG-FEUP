#pragma once

#include <string>

enum ProgramType {
	MOVIE,
	NEWS,
	SPORTS,
	ENTERTAINMENT,
	LIFE_STYLE
};

std::string ToLower(std::string str);
int FormatName(std::string& str);
std::string getProgramTypeString(ProgramType type);
