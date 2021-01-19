#include "FighterSelect.hpp"

namespace game
{
	FighterSelect::FighterSelect(const InitData& init) : IScene(init)
	{
		this->allFighterData = loadData("./data/Fighters.txt");
		for (int i = 0; i < 2; i++)
		{
			this->fighter[i] = Fighter();
			this->fighterData[i] = FighterData();
		}
		this->selectCount = 0;
	}

	void FighterSelect::update()
	{
		// 戻るボタン
		if (isPressedBackButton())
		{
			changeScene(0);
		}

		// スタートボタン
		bool isSelect = (this->selectCount > 0 && this->selectCount % 2 == 0);
		if (SimpleGUI::Button(U"Start Game", Vec2(Scene::Center().x, 900), 200, isSelect))
		{
			for (int i = 0; i < 2; i++)
			{
				getData().fighter[i] = this->fighter[i];
			}
			changeScene(4);
		}
		// ファイター選択
		if (MouseL.down())
		{
			int cursorX = Cursor::Pos().x;
			int cursorY = Cursor::Pos().y;

			if (300 <= cursorX && cursorX <= 1000 && 185 <= cursorY && cursorY <= 185 + this->allFighterData.size() * 30)
			{
				int fighterNum = (cursorY - 185) / 30;

				// 1番目のキャラが選ばれていない OR
				// どちらも選ばれている
				if (this->selectCount % 2 == 0)
				{
					this->fighterData[0] = this->allFighterData[fighterNum];
					adaptData(this->fighter[0], this->fighterData[0]);
					this->selectCount++;
				}
				else
				{
					this->fighterData[1] = this->allFighterData[fighterNum];
					adaptData(this->fighter[1], this->fighterData[1]);
					this->selectCount++;
				}
			}
		}
	}

	void FighterSelect::draw() const
	{
		// Backボタン
		drawBackButton();

		// Fighterリスト
		Line(300, 200 - 15, 1000, 200 - 15).draw(Palette::Skyblue);
		for (int i = 0; i < this->allFighterData.size(); i++)
		{
			FontAsset(U"Normal")(this->allFighterData[i].showS()).drawAt(Scene::Center().x, 200 + i * 30, Palette::Black);
			Line(300, 200 + (i + 1) * 30 - 15, 1000, 200 + (i + 1) * 30 - 15).draw(Palette::Skyblue);
		}

		// fighterプレビュー
		if (this->selectCount > 0)
		{
			this->fighter[0].draw(50, 300);
		}
		if (this->selectCount > 1)
		{
			this->fighter[1].draw(800, 300);
		}
	}
}