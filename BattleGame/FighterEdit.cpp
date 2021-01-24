#include "FighterEdit.hpp"

namespace game
{
	FighterEdit::FighterEdit(const InitData& init) : IScene(init)
	{
		this->out = "./data/Fighters.txt";
		this->fighter = Fighter();
		this->fighterName = "No name";
		this->allFighterData = loadData(this->out);

		if (!getData().newFighter)
		{
			this->fighterNum = getData().fighterNum;
			adaptData(this->fighter, this->allFighterData[this->fighterNum]);
			this->fighterName = this->allFighterData[this->fighterNum].name;
		}

		this->selectPart = 0;
		this->selectColor = Palette::Black;

		this->name = TextEditState();
		this->red = TextEditState();
		this->green = TextEditState();
		this->blue = TextEditState();
	}

	void FighterEdit::update()
	{
		if (isPressedBackButton())
		{
			FighterEdit::saveFighterData();
			changeScene(1);
		}

		// Saveボタン
		if (SimpleGUI::Button(U"Save", Vec2(1500, 1000), 200))
		{
			FighterEdit::saveFighterData();
			changeScene(1);
		}

		// Cancelボタン
		if (SimpleGUI::Button(U"Cancel", Vec2(1700, 1000), 200))
		{
			changeScene(1);
		}

		// 色決定ボタン
		if (SimpleGUI::Button(U"Enter", Vec2(1400, 640)))
		{
			this->selectColor.r = Parse<uint32>(this->red.text);
			debug("red", Parse<uint32>(this->red.text));
			this->selectColor.g = Parse<uint32>(this->green.text);
			debug("green", Parse<uint32>(this->green.text));
			this->selectColor.b = Parse<uint32>(this->blue.text);
			debug("blue", Parse<uint32>(this->blue.text));

			this->fighter.setColor(this->selectPart, this->selectColor);
		}

		// 名前決定ボタン
		if (SimpleGUI::Button(U"Enter", Vec2(1350, 260)))
		{
			this->fighterName = this->name.text.narrow();
		}

		// 部位選択
		if (SimpleGUI::Button(U"Head", Point(1000, 400)))
		{
			this->selectPart = 0;
			debug("Part", this->selectPart);
			this->selectColor = this->fighter.getPart(0).color;
		}
		else if (SimpleGUI::Button(U"Body", Point(1000, 500)))
		{
			this->selectPart = 1;
			debug("Part", this->selectPart);
			this->selectColor = this->fighter.getPart(1).color;
		}
		else if (SimpleGUI::Button(U"Left Arm", Point(1000, 600)))
		{
			this->selectPart = 2;
			debug("Part", this->selectPart);
			this->selectColor = this->fighter.getPart(2).color;
		}
		else if (SimpleGUI::Button(U"Right Arm", Point(1000, 700)))
		{
			this->selectPart = 3;
			debug("Part", this->selectPart);
			this->selectColor = this->fighter.getPart(3).color;
		}
		else if (SimpleGUI::Button(U"Left Leg", Point(1000, 800)))
		{
			this->selectPart = 4;
			debug("Part", this->selectPart);
			this->selectColor = this->fighter.getPart(4).color;
		}
		else if (SimpleGUI::Button(U"Right Leg", Point(1000, 900)))
		{
			this->selectPart = 5;
			debug("Part", this->selectPart);
			this->selectColor = this->fighter.getPart(5).color;
		}
		else if (SimpleGUI::Button(U"Sord", Point(1000, 1000)))
		{
			this->selectPart = 6;
			debug("Part", this->selectPart);
			this->selectColor = this->fighter.getPart(6).color;
		}

		// テキストボックス
		SimpleGUI::TextBox(this->name, Vec2(1100, 260));
		SimpleGUI::TextBox(this->red, Vec2(1600, 400));
		SimpleGUI::TextBox(this->green, Vec2(1600, 480));
		SimpleGUI::TextBox(this->blue, Vec2(1600, 560));

		if (!this->name.active)
		{
			this->name.text = Unicode::Widen(this->fighterName);
		}

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
		this->fighter.draw(600, 400);
		// テキストボックスの名前
		FontAsset(U"Normal")(U"Name").drawAt(1050, 280, Palette::Black);
		FontAsset(U"Normal")(U"Red").drawAt(1400, 420, Palette::Black);
		FontAsset(U"Normal")(U"Green").drawAt(1400, 500, Palette::Black);
		FontAsset(U"Normal")(U"Blue").drawAt(1400, 580, Palette::Black);
	}
	
	void FighterEdit::saveFighterData()
	{
		debug("size", this->allFighterData.size());
		FighterData fd;
		toData(this->fighter, fd);
		fd.name = this->fighterName;

		if (!getData().newFighter)
		{
			this->allFighterData[this->fighterNum] = fd;
		}

		// data/Fighters.txtに保存
		resetFile(this->out);

		// ファイターを追加
		if (getData().newFighter)
		{
			fLine(this->out, fd.toS());
		}

		for (int i = 0; i < this->allFighterData.size(); i++)
		{
			fLine(this->out, this->allFighterData[i].toS());
		}
	}
}
