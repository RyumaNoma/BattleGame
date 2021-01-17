#pragma once

#include <Siv3D.hpp>
#include <fstream>
#include <string>
#include "Fighter.hpp"
#include "Function.hpp"
#include "SceneData.hpp"
#include "Button.hpp"

namespace game
{
	using App = SceneManager<int, SceneData>;

	class FighterEdit : public App::Scene
	{
	private:
		std::string out;
	public:
		FighterEdit(const InitData& init);
		void update() override;
		void draw() const override;
	};
}

