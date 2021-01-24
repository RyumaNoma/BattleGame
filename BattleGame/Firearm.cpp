#include "Firearm.hpp"

namespace game
{
	Firearm::Firearm()
	{
		this->body = BodyPart();
		this->pos = Point();
		this->direction = Direction::Left;
		this->flame = 0;
	}
}
