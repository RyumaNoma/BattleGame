#include "Fighter.hpp"

namespace game
{
	const int Fighter::BodyPartsCount = 7;

	Fighter::Fighter()
	{
		this->parts.resize(BodyPartsCount);
		for (int i = 0; i < Fighter::BodyPartsCount; i++)
		{
			this->parts[i] = { Palette::Black, 0, 1, 1, Point(), Point() };
		}
	}

	void Fighter::draw(int startX, int startY)
	{
		for (int i = 0; i < Fighter::BodyPartsCount; i++)
		{
			auto p = this->parts[i];
			Rect(p.base, p.width, p.height).rotatedAt(p.center, p.rotate).draw(p.color);
		}
	}
}