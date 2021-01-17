#include "FighterEditMenu.hpp"

namespace game
{
	FighterEditMenu::FighterEditMenu(const InitData& init) : IScene(init)
	{
		this->fileName = "./data/Fighters.txt";
		this->fighters = loadData(this->fileName);
	}

	void FighterEditMenu::update()
	{
	}

	void FighterEditMenu::draw() const
	{
		Scene::SetBackground(Palette::White);
		
		FontAsset(U"Title")(U"Fighter Edit Menu").drawAt(Scene::Center().x, 20, Palette::Black);
	}
}