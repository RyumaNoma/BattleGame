#pragma once

#include <Siv3D.hpp>
#include "SceneData.hpp"

namespace game
{
	using App = SceneManager<int, SceneData>;
	class Battle : App::Scene
	{
	private:
	public:
		Battle(const InitData& init);
		void update() override;
		void draw() const override;
	};
}

