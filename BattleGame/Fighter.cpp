#include "Fighter.hpp"

namespace game
{
	const int Fighter::BodyPartsCount = 7;

	const Color Fighter::colorTemplate[][7] = {
		{Palette::Red, Palette::Red, Palette::Red, Palette::Red, Palette::Blue, Palette::Blue, Palette::Gray}
	};

	int Fighter::sordHand()
	{
		if (this->direction == Direction::Left)
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}

	Fighter::Fighter()
	{
		this->parts.resize(BodyPartsCount);
		// “ª
		this->parts[0] = BodyPart( Palette::Black, 100, 100, Point(-50, 0), 0, Point(0, 100), 0, 0, 0 );
		// “·‘Ì
		this->parts[1] = BodyPart( Palette::Red, 50, 200, Point(-25, 100), 0, Point(0, 200), 0, 0, 0);
		// ¶˜r
		this->parts[2] = BodyPart( Palette::Blue, 100,20, Point(-125, 150), 0, Point(-25, 150), 0, 0, 0);
		// ‰E˜r
		this->parts[3] = BodyPart( Palette::Yellow, 100, 20, Point(25, 150), 0, Point(25, 150), 0, 0, 0);
		// ¶‘«
		this->parts[4] = BodyPart( Palette::Green, 20, 100, Point(-45, 300), 0, Point(-25, 300), 0, 0, 0);
		// ‰E‘«
		this->parts[5] = BodyPart( Palette::Purple, 20, 100, Point(25, 300), 0, Point(25, 300), 0, 0, 0);
		// Œ•
		this->parts[6] = BodyPart( Palette::Gray, 10, 150, Point(120, 10), 0, Point(25, 150), 0, 120, 160);

		// Œü‚«
		this->direction = Direction::Right;
	}

	BodyPart Fighter::getPart(int partID)
	{
		return this->parts[partID];
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

		// Œ•‚ð¶‰E”½“]
		this->parts[6].base.x *= -1;
		this->parts[6].center.x *= -1;
		this->parts[6].sordCenterX *= -1;
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

	void Fighter::setRotate(int partID, double rotate)
	{
		if (partID == Fighter::sordHand())
		{
			this->parts[3].rotate = ToRadians(rotate);
			this->parts[6].rotate = ToRadians(rotate);

			// ‰ŠúŽž‚Ì(sordRotate) - (rotate)
			constexpr int nowX = 95;
			constexpr int nowY = 10;
			this->parts[6].sordCenterX = nowX * std::cos(ToRadians(rotate)) - nowY * std::sin(ToRadians(rotate)) + this->parts[6].center.x;
			this->parts[6].sordCenterY = nowX * std::sin(ToRadians(rotate)) + nowY * std::cos(ToRadians(rotate)) + this->parts[6].center.y;
		}
		// Œ•
		else if (partID == 6)
		{
			this->parts[6].sordRotate = ToRadians(rotate);
		}
		else
		{
			this->parts[partID].rotate = ToRadians(rotate);
		}
	}

	void Fighter::addRotate(int partID, double rotate)
	{
		if (partID == Fighter::sordHand())
		{
			this->parts[3].rotate += ToRadians(rotate);
			this->parts[6].rotate = this->parts[3].rotate;

			const double nowX = this->parts[6].sordCenterX - this->parts[6].center.x;
			const double nowY = this->parts[6].sordCenterY - this->parts[6].center.y;
			this->parts[6].sordCenterX = nowX * std::cos(ToRadians(rotate)) - nowY * std::sin(ToRadians(rotate)) + this->parts[6].center.x;
			this->parts[6].sordCenterY = nowX * std::sin(ToRadians(rotate)) + nowY * std::cos(ToRadians(rotate)) + this->parts[6].center.y;
		}
		// Œ•
		else if (partID == 6)
		{
			this->parts[6].sordRotate += ToRadians(rotate);
		}
		else
		{
			this->parts[partID].rotate += ToRadians(rotate);
		}
	}

	void Fighter::draw(int startX, int startY) const
	{
		for (int i = 0; i < Fighter::BodyPartsCount; i++)
		{
			const auto& p = this->parts[i];
			Rect(p.base.x + startX, p.base.y + startY, p.width, p.height).rotatedAt(p.center + Point(startX, startY), p.rotate).rotatedAt(Point(static_cast<int>(p.sordCenterX), static_cast<int>(p.sordCenterY)) + Point(startX, startY), p.sordRotate).draw(p.color);
		}
	}

	void Fighter::adaptData(FighterData fd)
	{
		for (int i = 0; i < 7; i++)
		{
			Fighter::setColor(i, fd.color[i]);
		}
	}
}