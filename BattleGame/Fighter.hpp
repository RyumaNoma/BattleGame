#pragma once

#include <Siv3D.hpp>
#include <vector>
#include <cmath>
#include "BodyPart.hpp"
#include "Direction.hpp"
#include "FighterData.hpp"
#include "FighterState.hpp"

namespace game
{
	class Fighter
	{
	private:
		const static int BodyPartsCount;
		const static Color colorTemplate[][7];

		std::vector<BodyPart> parts;
		Direction direction;

		int flame;
		int motionNum;
		int inAirTime;
		FighterState state;
		int rigidityCount;
		int hp;
		// ÇªÇÃçUåÇÇ≈ëäéËÇ…É_ÉÅÅ[ÉWÇó^Ç¶ÇΩÇÁtrueÇ…Ç»ÇÈ
		bool giveDamage;

		int sordHand() const;
	public:
		Fighter();

		BodyPart getPart(int partID) const;
		void setPart(int partID, const BodyPart& bodyPart);
		void setAttack(int partID, bool isAttack);

		Direction getDirection() const;
		void setDirection(Direction direction);
		void revDirection();

		void setColor(int partID, Color color);
		void setColor(int colorTemplateID);

		void setRotate(int partID, double rotate);
		void addRotate(int partID, double rotate);

		int getFlame() const;
		void setFlame(int flame);
		void resetFlame();
		void incFlame();

		int getMotionNum() const;
		void setMotionNum(int motionNum);
		void resetMotionNum();

		int getInAirTime() const;
		void setInAirTime(int inAirTime);
		void resetInAirTime();
		void incInAirTime();

		FighterState getState() const;
		void setState(FighterState state);

		int getRigidityCount() const;
		void setRigidityCount(int rigidiryFlame);
		void decRigidity();

		int getHP() const;
		void hitDamage(int damage);

		bool getGiveDamage() const;
		void setGiveDamage(bool giveDamage);

		void draw(int startX, int startY) const;

		friend void toData(const Fighter& fighter, FighterData& fd);
		friend void adaptData(Fighter& fighter, const FighterData& fd);
	};
}