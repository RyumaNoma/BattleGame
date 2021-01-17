#include "FighterEdit.hpp"

namespace game
{
	FighterEdit::FighterEdit(const InitData& init) : IScene(init)
	{
		this->out = "data/Fighters.txt";
		this->fighter = Fighter();
		this->fighterData = FighterData();

		if (!getData().newFighter)
		{
			std::vector<FighterData> fd = loadData("./data/Fighters.txt");
			this->fighterData = fd[getData().fighterNum];

			for (int i = 0; i < 7; i++)
			{
				this->fighter.setColor(i, fd[getData().fighterNum].color[i]);
			}
		}
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

		this->fighter.draw(300, 200);
	}
}
