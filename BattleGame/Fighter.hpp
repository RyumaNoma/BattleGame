#pragma once

#include <Siv3D.hpp>
#include <vector>
#include <cmath>
#include "BodyPart.hpp"
#include "Direction.hpp"

namespace game
{
	class Fighter
	{
	private:
		const static int BodyPartsCount;
		const static Color colorTemplate[][7];

		std::vector<BodyPart> parts;
		Direction direction;

		int sordHand();
	public:
		Fighter();

		void setDirection(Direction direction);
		void revDirection();

		void setColor(int partID, Color color);
		void setColor(int colorTemplateID);

		void setRotate(int partID, double rotate);
		void addRotate(int partID, double rotate);

		void draw(int startX, int startY);
	};
}