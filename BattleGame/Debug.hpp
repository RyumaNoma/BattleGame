#pragma once

#include <fstream>
#include <utility>
#include <cstdio>
#include <string>
#include "Function.hpp"

namespace game
{
	void debugReset(void);

	void debug(std::string str);
	void debug(const char* format, const int& value);
}