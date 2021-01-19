#pragma once

#include <Siv3D.hpp>

namespace game
{
	class BodyPart
	{
	public:
		Color color;
		int width;
		int height;
		Point base;

		double rotate;
		Point center;

		double sordRotate;
		double sordCenterX;
		double sordCenterY;

		bool isAttack;
		bool isVisible;

		BodyPart();
		BodyPart(Color color, int width, int height, Point base, double rotate, Point center, double sordRotate, double sordCenterX, double sordCenterY, bool isAttack, bool isVisible);
	};
}

