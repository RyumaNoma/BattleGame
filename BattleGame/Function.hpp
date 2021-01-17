#pragma once

#include <string>
#include <fstream>
#include <utility>

namespace game
{
	char* toC(const std::string& str);

	template<class... Args>
	bool fLine(const std::string& fileName, const char* mode, const char& format, Args... args);

	template<class... Args>
	bool fLine(const std::string& fileName, const char* mode, std::string str);
}