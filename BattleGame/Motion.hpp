#pragma once

#include <cmath>
#include "Fighter.hpp"
#include "BodyPart.hpp"
#include "Direction.hpp"

namespace game
{
	namespace motion
	{
		// å„çdíº, É_ÉÅÅ[ÉW
		extern const int motionTable[3][2];

		void jump(Fighter& fighter, int& fighterX, int& fighterY);
		void rotateSord(Fighter& fighter, int& fighterX, int& fighterY);
		void throwSord(Fighter& fighter, int& fighterX, int& fighterY);
		void shield(Fighter& fighter, int& fighterX, int& fighterY);
	}
}
