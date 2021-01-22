#pragma once

#include <Siv3D.hpp>

namespace game
{
	class Cursor
	{
	private:
		Point point;
		int padID;
		// �����ꂽ��true
		bool buttonA;
		// �����ꑱ���Ă�����true
		bool keep;
	public:
		Cursor();
		Cursor(Point point, int padID);

		Point getPos() const;

		bool isPressed() const;
		bool isPressed(const int& startX, const int& startY, const int& endX, const int& endY) const;
		bool isPressedBackButton() const;

		// gamepad���ڑ�����Ă�����true
		bool update();
		bool draw() const;
	};
}

