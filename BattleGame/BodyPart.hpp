#pragma once

#include <Siv3D.hpp>

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

		BodyPart();
		BodyPart(Color color, int rotate, int width, int height, Point base, Point center);
	};
}

