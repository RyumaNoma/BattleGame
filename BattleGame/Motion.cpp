#include "Motion.hpp"

namespace game
{
	namespace motion
	{
		void jump(Fighter& fighter, int& fighterX, int& fighterY)
		{
			fighter.incFlame();
			fighterY -= 5 * ((fighter.getFlame() < 30) ? 1 : -1);

			if (fighter.getFlame() == 60)
			{
				fighter.resetFlame();
				fighter.resetMotionNum();
			}
		}
	}
}
