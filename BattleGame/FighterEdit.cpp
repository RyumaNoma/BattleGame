#include "FighterEdit.hpp"

namespace game
{
	FighterEdit::FighterEdit(const InitData& init) : IScene(init)
	{
		this->out = "data/Fighters.txt";
	}

	void FighterEdit::update()
	{
		if (isPressedBackButton())
		{
			changeScene(1);
		}
	}

	void FighterEdit::draw() const
	{
		FontAsset(U"Title")(U"Fighter Edit").drawAt(Scene::Center().x, 50, Palette::Black);
		drawBackButton();

		Fighter fighter;
		fighter.draw(300, 100);
	}
}
