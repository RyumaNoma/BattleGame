#pragma once

#include <Siv3D.hpp>
#include <vector>

namespace game
{
	class BodyPart
	{
	public:
		Color color;
		int rotate;
		int width;
		int height;
		Point base;
		Point center;
	};

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