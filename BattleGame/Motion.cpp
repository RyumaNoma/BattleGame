#include "Motion.hpp"

namespace game
{
	namespace motion
	{
		void jump(Fighter& fighter, int& fighterX, int& fighterY)
		{
			int lastPos = -sin(fighter.getInAirTime() / 50.0 * Math::Pi) * 100;
			fighter.incInAirTime();
			int nowPos = -sin(fighter.getInAirTime() / 50.0 * Math::Pi) * 100;
			
			fighterY += nowPos - lastPos;

			if (fighter.getInAirTime() == 50)
			{
				fighter.resetInAirTime();
			}
		}

		void rotateSord(Fighter& fighter, int& fighterX, int& fighterY)
		{
			fighter.incFlame();
			fighter.addRotate(6, 18);

			if (fighter.getFlame() == 20)
			{
				fighter.resetFlame();
				fighter.resetMotionNum();
				fighter.setRigidityCount(60);
			}
		}
	}
}
