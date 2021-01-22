#include "Cursor.hpp"

namespace game
{
	Cursor::Cursor()
	{
		this->point = Point(Scene::Center());
		this->padID = 0;
	}

	Cursor::Cursor(Point point, int padID)
	{
		this->point = point;
		this->padID = padID;
	}

	bool Cursor::isPressed() const
	{
		return this->buttonA;
	}

	bool Cursor::update()
	{
		if (const auto gamepad = Gamepad(this->padID))
		{
			// 左
			if (gamepad.axes[0] < 0.5)
			{
				this->point.x -= 5;
			}
			// 右
			else if (gamepad.axes[0] > 0.5)
			{
				this->point.x += 5;
			}

			// 上
			if (gamepad.axes[1] < 0.5)
			{
				this->point.y -= 5;
			}
			// 下
			else if (gamepad.axes[1] > 0.5)
			{
				this->point.y += 5;
			}

			// Aぼたんがおされていたら
			if (gamepad.buttons[0].pressed())
			{
				this->buttonA = true;
			}
			else
			{
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