#include "FighterEdit.hpp"

namespace game
{
	FighterEdit::FighterEdit(const InitData& init) : IScene(init)
	{
		this->out = "data/Fighters.txt";
		this->fighter = Fighter();

		if (!getData().newFighter)
		{
			this->allFighterData = loadData("./data/Fighters.txt");

			this->fighterNum = getData().fighterNum;

			adaptData(this->fighter, this->allFighterData[this->fighterNum]);
		}

		this->selectPart = 0;
		this->selectColor = Palette::Black;

		this->red = TextEditState();
		this->green = TextEditState();
		this->blue = TextEditState();
	}

	void FighterEdit::update()
	{
		if (isPressedBackButton())
		{
			changeScene(1);
		}

		if (SimpleGUI::Button(U"Head", Point(500, 200)))
		{
			this->selectPart = 0;
			debug("Part", this->selectPart);
			this->selectColor = this->fighter.getPart(0).color;
		}
		else if (SimpleGUI::Button(U"Body", Point(500, 250)))
		{
			this->selectPart = 1;
			debug("Part", this->selectPart);
			this->selectColor = this->fighter.getPart(1).color;
		}
		else if (SimpleGUI::Button(U"Left Arm", Point(500, 300)))
		{
			this->selectPart = 2;
			debug("Part", this->selectPart);
			this->selectColor = this->fighter.getPart(2).color;
		}
		else if (SimpleGUI::Button(U"Right Arm", Point(500, 350)))
		{
			this->selectPart = 3;
			debug("Part", this->selectPart);
			this->selectColor = this->fighter.getPart(3).color;
		}
		else if (SimpleGUI::Button(U"Left Leg", Point(500, 400)))
		{
			this->selectPart = 4;
			debug("Part", this->selectPart);
			this->selectColor = this->fighter.getPart(4).color;
		}
		else if (SimpleGUI::Button(U"Right Leg", Point(500, 450)))
		{
			this->selectPart = 5;
			debug("Part", this->selectPart);
			this->selectColor = this->fighter.getPart(5).color;
		}
		else if (SimpleGUI::Button(U"Sord", Point(500, 500)))
		{
			this->selectPart = 6;
			debug("Part", this->selectPart);
			this->selectColor = this->fighter.getPart(6).color;
		}

		// 決定ボタン
		if (SimpleGUI::Button(U"Enter", Vec2(700, 320)))
		{
			this->selectColor.r = Parse<uint32>(this->red.text);
			debug("red", Parse<uint32>(this->red.text));
			this->selectColor.g = Parse<uint32>(this->green.text);
			debug("green", Parse<uint32>(this->green.text));
			this->selectColor.b = Parse<uint32>(this->blue.text);
			debug("blue", Parse<uint32>(this->blue.text));
			this->fighter.setColor(this->selectPart, this->selectColor);
		}

		// テキストボックス
		SimpleGUI::TextBox(this->red, Vec2(700, 200));
		SimpleGUI::TextBox(this->green, Vec2(700, 240));
		SimpleGUI::TextBox(this->blue, Vec2(700, 280));

		if (!(this->red.active || this->green.active || this->blue.active))
		{
			this->red.text = Format(this->selectColor.r);
			this->green.text = Format(this->selectColor.g);
			this->blue.text = Format(this->selectColor.b);
		}
	}

	void FighterEdit::draw() const
	{
		// タイトル
		FontAsset(U"Title")(U"Fighter Edit").drawAt(Scene::Center().x, 50, Palette::Black);
		// Backボタン
		drawBackButton();
		// プレビュー
		this->fighter.draw(300, 200);
	}
	
	void FighterEdit::saveFighterData()
	{
		// 現在表示しているファイターをFighterDataにする
		FighterData fd;
		toData(this->fighter, fd);

		if (getData().newFighter)
		{
			
			this->allFighterData.push_back(fd);
		}
		else
		{
			this->allFighterData[this->fighterNum] = fd;
		}

		// data/Fighters.txtに保存
		resetFile("data/Fighters.txt");
		for (int i = 0; i < this->allFighterData.size(); i++)
		{
			fLine("data/Fighters.txt", this->allFighterData[i].toS());
		}
	}
}
