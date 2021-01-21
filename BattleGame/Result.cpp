#include "Result.hpp"

namespace game
{
	Result::Result(const InitData& init) : IScene(init)
	{
	}

	void Result::update()
	{
		if (isPressedBackButton())
		{
			changeScene(0);
		}
	}

	void Result::draw() const
	{
		drawBackButton();
		FontAsset(U"Title")(U"{}P WIN"_fmt(getData().winner + 1)).drawAt(Scene::Center().x, 100, Palette::Black);
		getData().fighter[getData().winner].draw(Scene::Center().x, 300);
	}
}