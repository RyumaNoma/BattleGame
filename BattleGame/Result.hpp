#pragma once

#include <Siv3D.hpp>
#include "SceneData.hpp"
#include "Fighter.hpp"
#include "Button.hpp"

namespace game
{
	using App = SceneManager<int, SceneData>;
	class Result : public App::Scene
	{
	private:
	public:
		Result(const InitData& init);
		void update() override;
		void draw() const override;
	};
}

