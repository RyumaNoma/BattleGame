#pragma once

#include <Siv3D.hpp>

namespace game
{
	class Cursor
	{
	private:
		Point point;
		int padID;
		// 押されたらtrue
		bool buttonA;
		// 押され続けていたらtrue
		bool keep;
	public:
		Cursor();
		Cursor(Point point, int padID);

		Point getPos() const;

		bool isPressed() const;
		bool isPressed(const int& startX, const int& startY, const int& endX, const int& endY) const;
		bool isPressedBackButton() const;

		// gamepadが接続されていたらtrue
		bool update();
		bool draw() const;
	};
}

