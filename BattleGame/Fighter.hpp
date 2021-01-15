#pragma once

#include <Siv3D.hpp>
#include <vector>
#include "BodyPart.hpp"
#include "Direction.hpp"

namespace game
{
	class Fighter
	{
	private:
		const static int BodyPartsCount;

		std::vector<BodyPart> parts;
		Direction direction;
	public:
		Fighter();

		void setDirection(Direction direction);
		void revDirection();

		void draw(int startX, int startY);
	};
}