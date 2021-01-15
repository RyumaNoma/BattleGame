#include "BodyPart.hpp"

namespace game
{
	BodyPart::BodyPart()
	{
		this->color = Palette::Black;
		this->rotate = 0;
		this->width = 1;
		this->height = 1;
		this->base = Point();
		this->center = Point();
	}

	BodyPart::BodyPart(Color color, int rotate, int width, int height, Point base, Point center)
	{
		this->color = color;
		this->rotate = rotate;
		this->width = width;
		this->height = height;
		this->base = base;
		this->center = center;
	}
}
