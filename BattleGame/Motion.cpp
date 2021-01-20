#include "Motion.hpp"

namespace game
{
	namespace motion
	{
		void jump(Fighter& fighter, int& fighterX, int& fighterY)
		{
			int lastPos = -sin(fighter.getFlame() / 50.0 * Math::Pi) * 100;
			fighter.incFlame();
			int nowPos = -sin(fighter.getFlame() / 50.0 * Math::Pi) * 100;
			
			fighterY += nowPos - lastPos;

			if (fighter.getFlame() == 50)
			{
				fighter.resetFlame();
				fighter.resetMotionNum();
			}
		}
	}
}
