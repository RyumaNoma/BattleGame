#include "Cursor.hpp"

namespace game
{
	Cursor::Cursor()
	{
		this->point = Point(Scene::Center());
		this->padID = 0;
		this->buttonA = false;
		this->keep = false;
	}

	Cursor::Cursor(Point point, int padID)
	{
		this->point = point;
		this->padID = padID;
		this->buttonA = false;
	}

	Point Cursor::getPos() const
	{
		return this->point;
	}

	bool Cursor::isPressed() const
	{
		return this->buttonA;
	}

	bool Cursor::isPressed(const int& startX, const int& startY, const int& endX, const int& endY) const
	{
		if (this->buttonA)
		{
			if (startX <= this->point.x && this->point.x <= endX &&
				startY <= this->point.y && this->point.y <= endY)
			{
				return true;
			}
		}

		return false;
	}

	bool Cursor::isPressedBackButton() const
	{
		return Cursor::isPressed(0, 0, 200, 100);
	}

	bool Cursor::update()
	{
		if (const auto gamepad = Gamepad(this->padID))
		{
			// 左
			if (gamepad.axes[0] < -0.5)
			{
				this->point.x -= 5;
			}
			// 右
			else if (gamepad.axes[0] > 0.5)
			{
				this->point.x += 5;
			}

			// 上
			if (gamepad.axes[1] < -0.5)
			{
				this->point.y -= 5;
			}
			// 下
			else if (gamepad.axes[1] > 0.5)
			{
				this->point.y += 5;
			}

			// Aぼたんがおされ始めたら
			if (gamepad.buttons[0].pressed())
			{
				if (this->keep)
				{
					this->buttonA = false;
				}
				else
				{
					this->buttonA = true;
					this->keep = true;
				}
			}
			else
			{
				this->keep = false;
				this->buttonA = false;
			}

			return true;
		}
		else
		{
			return false;
		}
	}

	bool Cursor::draw() const
	{
		if (Gamepad(this->padID))
		{
			Color color = (this->padID == 0) ? Palette::Red : Palette::Blue;

			Circle(this->point, 10).draw(color);

			return true;
		}
		else
		{
			return false;
		}
	}
}