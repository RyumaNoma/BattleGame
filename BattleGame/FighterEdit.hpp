#pragma once

#include <Siv3D.hpp>
#include "Fighter.hpp"

namespace game
{
	using App = SceneManager<int>;

	class FighterEdit : public App::Scene
	{
	private:
		int a;
	public:
		FighterEdit(const InitData& init);

		void update() override;
		void draw() const override;
	};
}

