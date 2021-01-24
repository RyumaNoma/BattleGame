#include "Motion.hpp"

namespace game
{
	namespace motion
	{
		// 後硬直, ダメージ
		const int motionTable[5][2] = {
			{0, 0},
			{30, 10},// rotateSord
			{30, 10},// throwSord
			{30, 10},// grab
			{30, 10},// slashWave
		};

		void jump(Fighter& fighter, int& fighterX, int& fighterY)
		{
			int lastPos = -sin(fighter.getInAirTime() / 50.0 * Math::Pi) * 400;
			fighter.incInAirTime();
			int nowPos = -sin(fighter.getInAirTime() / 50.0 * Math::Pi) * 400;
			
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

		void shield(Fighter& fighter, int& fighterX, int& fighterY)
		{
			Circle(fighterX, fighterY + 200, 220).draw(Color(100, 168, 50, 100));
		}

		void grab(Fighter& fighter, int& fighterX, int& fighterY)
		{
			if (fighter.getFlame() == 1)
			{
				fighter.setAttack(3, true);
			}

			fighter.incFlame();

			if (fighter.getFlame() == 5)
			{
				fighter.setAttack(3, false);
				fighter.resetFlame();
				fighter.resetMotionNum();
				fighter.setRigidityCount(motionTable[3][0]);
			}
		}

		void blast(Fighter& fighter, int& fighterX, int& fighterY, Direction direction, int distX, int distY)
		{
			fighterX += (direction == Direction::Left) ? -distX : distX;
			fighterY -= distY;
		}
	
		void slashWave(Fighter& fighter, int& fighterX, int& fighterY, Direction direction, Firearm& firearm)
		{
			fighter.incFlame();

			// 見た目の設定
			firearm.body.color = Palette::Purple;
			firearm.body.width = 40;
			firearm.body.height = 200;
			firearm.body.isAttack = true;
			firearm.body.isVisible = true;

			// 発生位置・向きの設定
			firearm.pos.x = fighterX + ((direction == Direction::Left) ? -20 : 20);
			firearm.pos.y = fighterY;
			firearm.direction = direction;

			// IDの設定
			firearm.id = 5;

			if (fighter.getFlame() == 1)
			{
				fighter.resetFlame();
				fighter.resetMotionNum();
				fighter.setRigidityCount(motionTable[4][0]);
			}
		}
	
		void slashWave(Firearm& firearm)
		{
			++firearm.flame;
			firearm.pos.x += ((firearm.direction == Direction::Left) ? -10 : 10);
		}
	}
}
