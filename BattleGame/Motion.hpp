#pragma once

#include "Fighter.hpp"
#include <cmath>

namespace game
{
	namespace motion
	{
		// å„çdíº, É_ÉÅÅ[ÉW
		extern const int motionTable[2][2];

		void jump(Fighter& fighter, int& fighterX, int& fighterY);
		void rotateSord(Fighter& fighter, int& fighterX, int& fighterY);
	}
}
