#include "Firearm.hpp"

namespace game
{
	Firearm::Firearm()
	{
		this->body = BodyPart();
		this->pos = Point();
		this->direction = Direction::Left;
		this->flame = 0;
		this->id = 0;
	}

	void Firearm::draw() const
	{
		const auto& p = this->body;
		if (p.isVisible)
			Rect(p.base.x + this->pos.x,
				p.base.y + this->pos.y,
				p.width,
				p.height)
			.rotatedAt(p.center + this->pos, p.rotate)
			.rotatedAt(Point(static_cast<int>(p.sordCenterX),
				static_cast<int>(p.sordCenterY)) + this->pos,
				p.sordRotate)
			.draw(p.color);
	}
}
