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
			this->fighters[i] = fd[i].showS();
		}
	}

	void FighterEditMenu::update()
	{
		if (SimpleGUI::Button(U"New Fighter", Vec2(1000, 50)))
		{
			getData().newFighter = true;
			getData().fighterNum = -1;
			changeScene(2);
		}
		else if (MouseL.down())
		{
			int cursorX = Cursor::Pos().x;
			int cursorY = Cursor::Pos().y;

			if (300 <= cursorX && cursorX <= 1000 && 185 <= cursorY && cursorY <= 185 + this->fighters.size() * 30)
			{
				int fighterNum = (cursorY - 185) / 30;
				debug("fighterNum", fighterNum);
				getData().newFighter = false;
				getData().fighterNum = fighterNum;
				changeScene(2);
			}
		}
	}

	void FighterEditMenu::draw() const
	{
		FontAsset(U"Title")(U"Fighter Edit Menu").drawAt(Scene::Center().x, 50, Palette::Black);

		Line(300, 200 - 15, 1000, 200 - 15).draw(Palette::Skyblue);
		for (int i = 0; i < fighters.size(); i++)
		{
			FontAsset(U"Normal")(this->fighters[i]).drawAt(Scene::Center().x, 200 + i * 30, Palette::Black);
			Line(300, 200 + (i+1) * 30 - 15, 1000, 200 + (i+1) * 30 - 15).draw(Palette::Skyblue);
		}
	}
}