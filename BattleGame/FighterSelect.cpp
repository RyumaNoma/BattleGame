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

		for (int i = 0; i < 2; i++)
		{
			this->cursor[i] = Cursor(Scene::Center(), i);
		}
	}

	void FighterSelect::update()
	{
		for (int i = 0; i < 2; i++)
		{
			this->cursor[i].update();
		}

		// 戻るボタン
		if (isPressedBackButton() ||
			this->cursor[0].isPressedBackButton() ||
			this->cursor[1].isPressedBackButton())
		{
			changeScene(0);
		}

		// スタートボタン
		bool isSelect = (this->isSelect[0] && this->isSelect[1]);
		if ((this->cursor[0].isPressed(Scene::Center().x - 100, 800, Scene::Center().x + 100, 870) ||
			this->cursor[1].isPressed(Scene::Center().x - 100, 800, Scene::Center().x + 100, 870)) &&
			isSelect)
		{
			for (int i = 0; i < 2; i++)
			{
				getData().fighter[i] = this->fighter[i];
			}
			changeScene(4);
		}

		// ファイター選択
		if (this->cursor[0].isPressed())
		{
			int cursorX = this->cursor[0].getPos().x;
			int cursorY = this->cursor[0].getPos().y;

			if (Scene::Center().x - 700 <= cursorX && cursorX <= Scene::Center().x + 700 &&
				185 <= cursorY && cursorY < 185 + this->allFighterData.size() * 30)
			{
				int fighterNum = (cursorY - 185) / 30;

				this->fighterData[0] = this->allFighterData[fighterNum];
				adaptData(this->fighter[0], this->fighterData[0]);
				this->isSelect[0] = true;
			}
		}
		else if (this->cursor[1].isPressed())
		{
			int cursorX = this->cursor[1].getPos().x;
			int cursorY = this->cursor[1].getPos().y;

			if (Scene::Center().x - 700 <= cursorX && cursorX <= Scene::Center().x + 700 &&
				185 <= cursorY && cursorY < 185 + this->allFighterData.size() * 30)
			{
				int fighterNum = (cursorY - 185) / 30;

				this->fighterData[1] = this->allFighterData[fighterNum];
				adaptData(this->fighter[1], this->fighterData[1]);
				this->isSelect[1] = true;
			}
		}
	}

	void FighterSelect::draw() const
	{
		// Backボタン
		drawBackButton();

		// Start Game
		drawButton(U"Start Game", Palette::Black, Scene::Center().x - 100, 800, Scene::Center().x + 100, 870);

		// Fighterリスト
		Line(Scene::Center().x - 700, 200 - 15, Scene::Center().x + 700, 200 - 15).draw(Palette::Skyblue);
		for (int i = 0; i < this->allFighterData.size(); i++)
		{
			FontAsset(U"Normal")(this->allFighterData[i].showS()).drawAt(Scene::Center().x, 200 + i * 30, Palette::Black);
			Line(Scene::Center().x - 700, 200 + (i + 1) * 30 - 15, Scene::Center().x + 700, 200 + (i + 1) * 30 - 15).draw(Palette::Skyblue);
		}

		// fighterプレビュー
		if (this->isSelect[0])
		{
			this->fighter[0].draw(Scene::Center().x - 700, 600);
		}
		if (this->isSelect[1])
		{
			this->fighter[1].draw(Scene::Center().x + 700, 600);
		}

		// Cursor
		for (int i = 0; i < 2; i++)
		{
			this->cursor[i].draw();
		}
	}
}