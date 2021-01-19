#pragma once

#include <Siv3D.hpp>
#include "SceneData.hpp"

namespace game
{
	using App = SceneManager<int, SceneData>;

	class MainMenu : public App::Scene
	{
	public:
		MainMenu(const InitData& init);
		void update() override;
		void draw() const override;
	};
}

