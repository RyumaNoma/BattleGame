#include "Button.hpp"

namespace game
{
	bool isPressed(int startX, int startY, int endX, int endY)
	{
		int cursorX = Cursor::Pos().x;
		int cursorY = Cursor::Pos().y;
		if (MouseL.down() &&
			startX <= cursorX && cursorX <= endX &&
			startY <= cursorY && cursorY <= endY)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void drawButton(String str, Color color, int startX, int startY, int endX, int endY)
	{
		Line(startX, startY, endX, startY).draw(color);
		Line(endX, startY, endX, endY).draw(color);
		Line(endX, endY, startX, endY).draw(color);
		Line(startX, endY, startX, startY).draw(color);

		FontAsset(U"Normal")(str).drawAt((startX + endX) / 2, (startY + endY) / 2, color);
	}

	void drawBackButton()
	{
		FontAsset(U"Normal")(U"Back").drawAt(50, 25, Palette::Black);
		// cü
		Line(100, 0, 100, 50).draw(Palette::Black);
		// ‰¡ü
		Line(0, 50, 100, 50).draw(Palette::Black);
	}

	bool isPressedBackButton()
	{
		return isPressed(0, 0, 100, 50);
	}
}