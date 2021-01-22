#pragma once

#include <Siv3D.hpp>

namespace game
{
	class Cursor
	{
	private:
		Point point;
		int padID;
		// 押されていたらtrue
		bool buttonA;
	public:
		Cursor();
		Cursor(Point point, int padID);

		bool isPressed() const;

		// gamepadが接続されていたらtrue
		bool update();
		bool draw() const;
	};
}

