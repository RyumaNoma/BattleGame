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
		// 頭
		this->parts[0] = BodyPart( Palette::Black, 100, 100, Point(-50, 0), 0, Point(0, 100), 0, 0, 0, false, true);
		// 胴体
		this->parts[1] = BodyPart( Palette::Red, 50, 200, Point(-25, 100), 0, Point(0, 200), 0, 0, 0, false, true);
		// 左腕
		this->parts[2] = BodyPart( Palette::Blue, 100,20, Point(-125, 150), 0, Point(-25, 150), 0, 0, 0, false, true);
		// 右腕
		this->parts[3] = BodyPart( Palette::Yellow, 100, 20, Point(25, 150), 0, Point(25, 150), 0, 0, 0, false, true);
		// 左足
		this->parts[4] = BodyPart( Palette::Green, 20, 100, Point(-45, 300), 0, Point(-25, 300), 0, 0, 0, false, true);
		// 右足
		this->parts[5] = BodyPart( Palette::Purple, 20, 100, Point(25, 300), 0, Point(25, 300), 0, 0, 0, false, true);
		// 剣
		this->parts[6] = BodyPart( Palette::Gray, 10, 150, Point(120, 10), 0, Point(25, 150), 0, 120, 160, false, true);

		// 向き
		this->direction = Direction::Right;
		// 現在のフレーム数
		this->flame = 0;
		// モーションの番号
		this->motionNum = 0;
		// 空中にいる時間(地上にいるときは0)
		this->inAirTime = 0;
	}

	BodyPart Fighter::getPart(int partID) const
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
		// 左腕と右腕を交換
		BodyPart temp = this->parts[2];
		this->parts[2] = this->parts[3];
		this->parts[3] = temp;
		// 色を戻す
		Color c = this->parts[2].color;
		this->parts[2].color = this->parts[3].color;
		this->parts[3].color = c;

		// 左足と右足を交換
		temp = this->parts[4];
		this->parts[4] = this->parts[5];
		this->parts[5] = temp;
		// 色を戻す
		c = this->parts[4].color;
		this->parts[4].color = this->parts[5].color;
		this->parts[5].color = c;

		// 剣を左右反転
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

			// 初期時の(sordRotate) - (rotate)
			constexpr int nowX = 95;
			constexpr int nowY = 10;
			this->parts[6].sordCenterX = nowX * std::cos(ToRadians(rotate)) - nowY * std::sin(ToRadians(rotate)) + this->parts[6].center.x;
			this->parts[6].sordCenterY = nowX * std::sin(ToRadians(rotate)) + nowY * std::cos(ToRadians(rotate)) + this->parts[6].center.y;
		}
		// 剣
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
		// 剣
		else if (partID == 6)
		{
			this->parts[6].sordRotate += ToRadians(rotate);
		}
		else
		{
			this->parts[partID].rotate += ToRadians(rotate);
		}
	}

	int Fighter::getFlame()
	{
		return this->flame;
	}

	void Fighter::setFlame(int flame)
	{
		this->flame = flame;
	}

	void Fighter::resetFlame()
	{
		Fighter::setFlame(0);
	}

	void Fighter::incFlame()
	{
		++this->flame;
	}

	int Fighter::getMotionNum()
	{
		return this->motionNum;
	}

	void Fighter::setMotionNum(int motionNum)
	{
		this->motionNum = motionNum;
	}

	void Fighter::resetMotionNum()
	{
		Fighter::setMotionNum(0);
	}

	int Fighter::getInAirTime()
	{
		return this->inAirTime;
	}

	void Fighter::setInAirTime(int inAirTime)
	{
		this->inAirTime = inAirTime;
	}

	void Fighter::resetInAirTime()
	{
		Fighter::setInAirTime(0);
	}

	void Fighter::draw(int startX, int startY) const
	{
		for (int i = 0; i < Fighter::BodyPartsCount; i++)
		{
			const auto& p = this->parts[i];
			if (p.isVisible)
				Rect(p.base.x + startX, p.base.y + startY, p.width, p.height).rotatedAt(p.center + Point(startX, startY), p.rotate).rotatedAt(Point(static_cast<int>(p.sordCenterX), static_cast<int>(p.sordCenterY)) + Point(startX, startY), p.sordRotate).draw(p.color);
		}
	}
}