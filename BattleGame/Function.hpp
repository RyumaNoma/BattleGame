#pragma once

#include <string>
#include <fstream>
#include <utility>

namespace game
{
	template<class... Args>
	bool fLine(std::string fileName, const char* mode, const char& format, Args... args);

	template<class... Args>
	bool fLine(std::string fileName, const char* mode, std::string str);
}