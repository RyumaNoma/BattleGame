#pragma once

#include <Siv3D.hpp>
#include <vector>
#include "BodyPart.hpp"

namespace game
{
	class Fighter
	{
	private:
		const static int BodyPartsCount;
		std::vector<BodyPart> parts;
	public:
		Fighter();

		void draw(int startX, int startY);
	};
}