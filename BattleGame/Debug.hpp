#pragma once

#include <fstream>
#include <utility>
#include <cstdio>
#include "Function.hpp"

namespace game
{
	void debugReset(void);

	void debug(const char* format, const int& value);
}