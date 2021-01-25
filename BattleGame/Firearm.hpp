#pragma once

#include <Siv3D.hpp>
#include "BodyPart.hpp"
#include "Direction.hpp"
#include "Debug.hpp"

namespace game
{
	class Firearm
	{
	public:
		BodyPart body;
		Point pos;
		Direction direction;
		int flame;
		int id;
		int fighterID;

		Firearm();
		void draw() const;
	};
}