#pragma once

#include <string>
#include <fstream>
#include <utility>

namespace game
{
	template<class... Args>
	bool addLine(std::string fileName, const char& format, Args... args);
	
	template<class... Args>
	bool writeLine(std::string fileName, const char& format, Args... args);
}