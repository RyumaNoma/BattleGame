#include "Fighter.hpp"

namespace game
{
	const int Fighter::BodyPartsCount = 7;

	Fighter::Fighter()
	{
		this->parts.resize(BodyPartsCount);
		// “ª
		this->parts[0] = BodyPart( Palette::Black, 0, 100, 100, Point(0, 0), Point(0, 0) );
		// “·‘Ì
		this->parts[1] = BodyPart( Palette::Red, 0, 50, 200, Point(25, 100), Point() );
		// ¶˜r
		this->parts[2] = BodyPart( Palette::Blue, 0, 100,20, Point(-75, 150), Point() );
		// ‰E˜r
		this->parts[3] = BodyPart( Palette::Yellow, 0, 100, 20, Point(75, 150), Point() );
		// ¶‘«
		this->parts[4] = BodyPart( Palette::Green, 0, 20, 100, Point(5, 300), Point() );
		// ‰E‘«
		this->parts[5] = BodyPart( Palette::Purple, 0, 20, 100, Point(75, 300), Point() );
		// Œ•
		this->parts[6] = BodyPart( Palette::Gray, 0, 10, 150, Point(170, 10), Point() );
	}

	void Fighter::draw(int startX, int startY)
	{
		for (int i = 0; i < Fighter::BodyPartsCount; i++)
		{
			const auto& p = this->parts[i];
			Rect(p.base.x + startX, p.base.y + startY, p.width, p.height).rotatedAt(p.center, p.rotate).draw(p.color);
		}
	}
}