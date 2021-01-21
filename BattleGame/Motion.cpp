#include "Motion.hpp"

namespace game
{
	namespace motion
	{
		// å„çdíº, É_ÉÅÅ[ÉW
		const int motionTable[3][2] = {
			{0, 0},
			{10, 10},// rotateSord
			{10, 5}// throwSord
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
			if (fighter.getFlame() == 1)
			{
				fighter.setAttack(6, true);
			}

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

		void throwSord(Fighter& fighter, int& fighterX, int& fighterY)
		{
			if (fighter.getFlame() == 1)
			{
				fighter.setAttack(6, true);
			}

			fighter.incFlame();
			BodyPart sord = fighter.getPart(6);
			
			if (fighter.getFlame() <= 10)
			{
				switch (fighter.getDirection())
				{
				case Direction::Left:
					sord.base.x -= 30;
					break;
				case Direction::Right:
					sord.base.x += 30;
					break;
				default:
					break;
				}
			}
			else
			{
				switch (fighter.getDirection())
				{
				case Direction::Left:
					sord.base.x += 30;
					break;
				case Direction::Right:
					sord.base.x -= 30;
					break;
				default:
					break;
				}
			}

			fighter.setPart(6, sord);

			if (fighter.getFlame() == 20)
			{
				fighter.setAttack(6, false);
				fighter.resetFlame();
				fighter.resetMotionNum();
				fighter.setRigidityCount(motionTable[2][0]);
			}
		}
	}
}
