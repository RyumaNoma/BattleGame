#pragma once

#include <string>
#include <fstream>
#include <utility>
#include <iostream>

namespace game
{
	char* toC(const std::string& str);

	bool fLine(const std::string& fileName, const std::string& str);
	bool fLine(const std::string& fileName, const char* str);
	bool fLine(const std::string& fileName, const char* tag, const int& value);
}