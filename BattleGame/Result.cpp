#include "Result.hpp"

namespace game
{
	Result::Result(const InitData& init) : IScene(init)
	{
		for (int i = 0; i < 2; i++)
		{
			this->cursor[i] = Cursor(Scene::Center(), i);
		}
	}

	void Result::update()
	{
		for (int i = 0; i < 2; i++)
		{
			this->cursor[i].update();
		}

		if (isPressedBackButton() ||
			this->cursor[0].isPressedBackButton() ||
			this->cursor[1].isPressedBackButton())
		{
			changeScene(0);
		}
	}

	void Result::draw() const
	{
		drawBackButton();
		FontAsset(U"Title")(U"{}P WIN"_fmt(getData().winner + 1)).drawAt(Scene::Center().x, 100, Palette::Black);
		getData().fighter[getData().winner].draw(Scene::Center().x, 300);

		for (int i = 0; i < 2; i++)
		{
			this->cursor[i].draw();
		}
	}
}