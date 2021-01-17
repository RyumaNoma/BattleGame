#include "FighterEditMenu.hpp"

namespace game
{
	FighterEditMenu::FighterEditMenu(const InitData& init) : IScene(init)
	{
		this->fileName = "./data/Fighters.txt";
		
		std::vector<FighterData> fd = loadData(this->fileName);
		this->fighters.resize(fd.size());
		for (int i = 0; i < fd.size(); i++)
		{
			this->fighters[i] = fd[i].toS();
		}
	}

	void FighterEditMenu::update()
	{
		if (SimpleGUI::Button(U"New Fighter", Vec2(1000, 50)))
		{
			getData().newFighter = true;
			changeScene(2);
		}
	}

	void FighterEditMenu::draw() const
	{
		FontAsset(U"Title")(U"Fighter Edit Menu").drawAt(Scene::Center().x, 50, Palette::Black);

		for (int i = 0; i < fighters.size(); i++)
		{
			FontAsset(U"Normal")(this->fighters[i]).drawAt(300, 100 + i * 30, Palette::Black);
		}
	}
}