#pragma once

#include "Fighter.hpp"
#include <cmath>

namespace game
{
	namespace motion
	{
		void jump(Fighter& fighter, int& fighterX, int& fighterY);
		void rotateSord(Fighter& fighter, int& fighterX, int& fighterY);
	}
}
