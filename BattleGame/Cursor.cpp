#include "Cursor.hpp"

namespace game
{
	Cursor::Cursor()
	{
		this->point = Point(Scene::Center());
		this->padID = 0;
		this->buttonA = false;
	}

	Cursor::Cursor(Point point, int padID)
	{
		this->point = point;
		this->padID = padID;
		this->buttonA = false;
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

	bool Cursor::update()
	{
		if (const auto gamepad = Gamepad(this->padID))
		{
			// ç∂
			if (gamepad.axes[0] < -0.5)
			{
				this->point.x -= 5;
			}
			// âE
			else if (gamepad.axes[0] > 0.5)
			{
				this->point.x += 5;
			}

			// è„
			if (gamepad.axes[1] < -0.5)
			{
				this->point.y -= 5;
			}
			// â∫
			else if (gamepad.axes[1] > 0.5)
			{
				this->point.y += 5;
			}

			// AÇ⁄ÇΩÇÒÇ™Ç®Ç≥ÇÍÇƒÇ¢ÇΩÇÁ
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