#include "Motion.hpp"

namespace game
{
	namespace motion
	{
		// å„çdíº, É_ÉÅÅ[ÉW
		const int motionTable[2][2] = {
			{0, 0},
			{10, 10}// Palu
		};

		void jump(Fighter& fighter, int& fighterX, int& fighterY)
		{
			int lastPos = -sin(fighter.getInAirTime() / 50.0 * Math::Pi) * 200;
			fighter.incInAirTime();
			int nowPos = -sin(fighter.getInAirTime() / 50.0 * Math::Pi) * 200;
			
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
			fighter.setAttack(6, true);

			if (fighter.getFlame() == 20)
			{
				fighter.setAttack(6, false);
				fighter.resetFlame();
				fighter.resetMotionNum();
				fighter.setRigidityCount(motionTable[1][0]);
			}
		}
	}
}
