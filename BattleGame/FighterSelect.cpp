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
			this->isSelect[i] = false;
		}
	}

	void FighterSelect::update()
	{
		// 戻るボタン
		if (isPressedBackButton())
		{
			changeScene(0);
		}

		// スタートボタン
		if (SimpleGUI::Button(U"Start Game", Vec2(Scene::Center().x, 900), 200, this->isSelect[0] && this->isSelect[1]))
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
				if (!this->isSelect[0] || (this->isSelect[0] && this->isSelect[1]))
				{
					this->fighterData[0] = this->allFighterData[fighterNum];
					adaptData(this->fighter[0], this->fighterData[0]);
					this->isSelect[0] = true;
				}
				else
				{
					this->fighterData[1] = this->allFighterData[fighterNum];
					adaptData(this->fighter[0], this->fighterData[1]);
					this->isSelect[1] = true;
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
			FontAsset(U"Normal")(this->allFighterData[i].name).drawAt(Scene::Center().x, 200 + i * 30, Palette::Black);
			Line(300, 200 + (i + 1) * 30 - 15, 1000, 200 + (i + 1) * 30 - 15).draw(Palette::Skyblue);
		}

		// fighterプレビュー
		if (this->isSelect[0])
		{
			this->fighter[0].draw(50, 500);
		}
		if (this->isSelect[1])
		{
			this->fighter[1].draw(900, 500);
		}
	}
}