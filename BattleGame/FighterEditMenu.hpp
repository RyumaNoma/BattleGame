#pragma once

#include <Siv3D.hpp>
#include <vector>
#include <string>
#include "SceneData.hpp"
#include "FighterData.hpp"

namespace game
{
	using App = SceneManager<int, SceneData>;

	class FighterEditMenu : public App::Scene
	{
	private:
		std::string fileName;
		std::vector<String> fighters;
	public:
		FighterEditMenu(const InitData& init);
		void update() override;
		void draw() const override;
	};
}