#pragma once

#include "Fighter.hpp"
#include <cmath>

namespace game
{
	namespace motion
	{
		// ��d��, �_���[�W
		extern const int motionTable[2][2];

		void jump(Fighter& fighter, int& fighterX, int& fighterY);
		void rotateSord(Fighter& fighter, int& fighterX, int& fighterY);
	}
}
