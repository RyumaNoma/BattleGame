#pragma once

#include <Siv3D.hpp>
#include <vector>
#include "SceneData.hpp"
#include "Function.hpp"
#include "Fighter.hpp"
#include "FighterData.hpp"
#include "Button.hpp"

namespace game
{
	using App = SceneManager<int, SceneData>;
	class FighterSelect : public App::Scene
	{
	private:
		std::vector<FighterData> allFighterData;
		Fighter fighter[2];
		FighterData fighterData[2];
		bool isSelect[2];

	public:
		FighterSelect(const InitData& init);
		void update() override;
		void draw() const override;
	};
}

