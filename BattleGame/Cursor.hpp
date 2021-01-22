#pragma once

#include <Siv3D.hpp>

namespace game
{
	class Cursor
	{
	private:
		Point point;
		int padID;
		// ‰Ÿ‚³‚ê‚Ä‚¢‚½‚çtrue
		bool buttonA;
	public:
		Cursor();
		Cursor(Point point, int padID);

		Point getPos() const;

		bool isPressed() const;
		bool isPressed(const int& startX, const int& startY, const int& endX, const int& endY) const;
		bool isPressedBackButton() const;

		// gamepad‚ªÚ‘±‚³‚ê‚Ä‚¢‚½‚çtrue
		bool update();
		bool draw() const;
	};
}

