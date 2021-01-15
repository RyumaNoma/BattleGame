#include "Fighter.hpp"

namespace game
{
	const int Fighter::BodyPartsCount = 7;

	const Color Fighter::colorTemplate[][7] = {
		{Palette::Red, Palette::Red, Palette::Red, Palette::Red, Palette::Blue, Palette::Blue, Palette::Gray}
	};

	Fighter::Fighter()
	{
		this->parts.resize(BodyPartsCount);
		// “ª
		this->parts[0] = BodyPart( Palette::Black, 0, 100, 100, Point(-50, 0), Point(0, 100) );
		// “·‘Ì
		this->parts[1] = BodyPart( Palette::Red, 0, 50, 200, Point(-25, 100), Point(0, 200) );
		// ¶˜r
		this->parts[2] = BodyPart( Palette::Blue, 0, 100,20, Point(-125, 150), Point(-25, 150) );
		// ‰E˜r
		this->parts[3] = BodyPart( Palette::Yellow, 0, 100, 20, Point(25, 150), Point(25, 150) );
		// ¶‘«
		this->parts[4] = BodyPart( Palette::Green, 0, 20, 100, Point(-45, 300), Point(-25, 300) );
		// ‰E‘«
		this->parts[5] = BodyPart( Palette::Purple, 0, 20, 100, Point(25, 300), Point(25, 300) );
		// Œ•
		this->parts[6] = BodyPart( Palette::Gray, 0, 10, 150, Point(120, 10), Point(120, 150) );

		// Œü‚«
		this->direction = Direction::Right;
	}

	void Fighter::setDirection(Direction direction)
	{
		if (this->direction != direction)
		{
			Fighter::revDirection();
			this->direction = direction;
		}
	}

	void Fighter::revDirection()
	{
		// ¶˜r‚Æ‰E˜r‚ðŒðŠ·
		BodyPart temp = this->parts[2];
		this->parts[2] = this->parts[3];
		this->parts[3] = temp;
		// F‚ð–ß‚·
		Color c = this->parts[2].color;
		this->parts[2].color = this->parts[3].color;
		this->parts[3].color = c;

		// ¶‘«‚Æ‰E‘«‚ðŒðŠ·
		temp = this->parts[4];
		this->parts[4] = this->parts[5];
		this->parts[5] = temp;
		// F‚ð–ß‚·
		c = this->parts[4].color;
		this->parts[4].color = this->parts[5].color;
		this->parts[5].color = c;

		this->parts[6].base.x *= -1;
	}

	void Fighter::setColor(int partID, Color color)
	{
		this->parts[partID].color = color;
	}

	void Fighter::setColor(int colorTemplateID)
	{
		for (int i = 0; i < Fighter::BodyPartsCount; i++)
		{
			this->parts[i].color = Fighter::colorTemplate[colorTemplateID][i];
		}
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