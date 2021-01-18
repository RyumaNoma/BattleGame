#pragma once

#include <Siv3D.hpp>
#include <fstream>
#include <string>
#include <vector>
#include "Fighter.hpp"
#include "Function.hpp"
#include "SceneData.hpp"
#include "Button.hpp"
#include "FighterData.hpp"

namespace game
{
	using App = SceneManager<int, SceneData>;

	class FighterEdit : public App::Scene
	{
	private:
		std::string out;
		// 表示用のファイター
		Fighter fighter;
		// 選ばれたファイターの番号
		int fighterNum;
		// 全ファイターのFighterData
		std::vector<FighterData> allFighterData;
		// 選ばれた部位
		int selectPart;
		// その部位の色
		Color selectColor;
		// テキストボックス
		TextEditState red;
		TextEditState green;
		TextEditState blue;
	public:
		FighterEdit(const InitData& init);
		void update() override;
		void draw() const override;

		void saveFighterData();
	};
}

