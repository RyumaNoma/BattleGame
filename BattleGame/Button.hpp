#pragma once

#include <Siv3D.hpp>

namespace game
{
	bool isPressed(int startX, int startY, int endX, int endY);
	void drawButton(String str, Color color, int startX, int startY, int endX, int endY);
	
	void drawBackButton();
	bool isPressedBackButton();
}
