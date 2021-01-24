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
		this->sordRotate = 0;
		this->sordCenterX = 0;
		this->sordCenterY = 0;
		this->isAttack = false;
		this->isVisible = true;
	}

	BodyPart::BodyPart(Color color, int width, int height, Point base, double rotate, Point center, double sordRotate, double sordCenterX, double sordCenterY, bool isAttack, bool isVisible)
	{
		this->color = color;
		this->rotate = rotate;
		this->width = width;
		this->height = height;
		this->base = base;
		this->center = center;
		this->sordRotate = sordRotate;
		this->sordCenterX = sordCenterX;
		this->sordCenterY = sordCenterY;
		this->isAttack = isAttack;
		this->isVisible = isVisible;
	}
}
