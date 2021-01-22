#pragma once

#include <Siv3D.hpp>

namespace game
{
	class Cursor
	{
	private:
		Point point;
		int padID;
		// ������Ă�����true
		bool buttonA;
	public:
		Cursor();
		Cursor(Point point, int padID);

		bool isPressed() const;

		// gamepad���ڑ�����Ă�����true
		bool update();
		bool draw() const;
	};
}

