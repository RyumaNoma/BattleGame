#include "MainMenu.hpp"

namespace game
{
	MainMenu::MainMenu(const InitData& init) : IScene(init)
	{
		for (int i = 0; i < 2; i++)
		{
			this->cursor[i] = Cursor(Scene::Center(), i);
		}
	}

	void MainMenu::update()
	{
		for (int i = 0; i < 2; i++)
		{
			this->cursor[i].update();
		}

		if (isPressed(100, 100, 400, 200) ||
			this->cursor[0].isPressed(100, 100, 400, 200) ||
			this->cursor[1].isPressed(100, 100, 400, 200))
		{
			changeScene(3);
		}

		if (isPressed(100, 300, 400, 400) ||
			this->cursor[0].isPressed(100, 300, 400, 400) ||
			this->cursor[1].isPressed(100, 300, 400, 400))
		{
			changeScene(1);
		}
	}

	void MainMenu::draw() const
	{
		drawButton(U"Fighter Select", Palette::Red, 100, 100, 400, 200);
		drawButton(U"Fighter Edit Menu", Palette::Blue, 100, 300, 400, 400);

		for (int i = 0; i < 2; i++)
		{
			this->cursor[i].draw();
		}
	}
}
