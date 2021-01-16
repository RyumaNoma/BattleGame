#pragma once

#include <Siv3D.hpp>

namespace game
{
	class BodyPart
	{
	public:
		Color color;
		double rotate;
		int width;
		int height;
		Point base;
		Point center;

		double sordRotate;
		Point sordCenter;

		BodyPart();
		BodyPart(Color color, double rotate, int width, int height, Point base, Point center, double sordRotate, Point sordCenter);
	};
}

