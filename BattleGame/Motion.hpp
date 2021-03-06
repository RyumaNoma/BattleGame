#pragma once

#include <cmath>
#include <vector>
#include "Fighter.hpp"
#include "BodyPart.hpp"
#include "Direction.hpp"
#include "Firearm.hpp"

namespace game
{
	namespace motion
	{
		// 後硬直, ダメージ
		extern const int motionTable[5][2];

		void jump(Fighter& fighter, int& fighterX, int& fighterY);
		void rotateSord(Fighter& fighter, int& fighterX, int& fighterY);
		void throwSord(Fighter& fighter, int& fighterX, int& fighterY);
		void shield(Fighter& fighter, int& fighterX, int& fighterY);
		void grab(Fighter& fighter, int& fighterX, int& fighterY);
		void blast(Fighter& fighter, int& fighterX, int& fighterY, Direction direction, int distX, int distY);
		void slashWave(Fighter& fighter, int& fighterX, int& fighterY, Direction direction, Firearm& firearm);
		void slashWave(Firearm& firearm);
	}
}
