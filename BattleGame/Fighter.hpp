#pragma once

#include <Siv3D.hpp>
#include <vector>
#include <cmath>
#include "BodyPart.hpp"
#include "Direction.hpp"
#include "FighterData.hpp"

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

		int sordHand();
	public:
		Fighter();

		BodyPart getPart(int partID) const;

		void setDirection(Direction direction);
		void revDirection();

		void setColor(int partID, Color color);
		void setColor(int colorTemplateID);

		void setRotate(int partID, double rotate);
		void addRotate(int partID, double rotate);

		int getFlame();
		void setFlame(int flame);
		void resetFlame();
		void incFlame();

		int getMotionNum();
		void setMotionNum(int motionNum);
		void resetMotionNum();

		void draw(int startX, int startY) const;

		friend void toData(const Fighter& fighter, FighterData& fd);
		friend void adaptData(Fighter& fighter, const FighterData& fd);
	};
}