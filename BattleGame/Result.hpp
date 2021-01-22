#pragma once

#include <Siv3D.hpp>
#include "SceneData.hpp"
#include "Fighter.hpp"
#include "Button.hpp"
#include "Cursor.hpp"

namespace game
{
	using App = SceneManager<int, SceneData>;
	class Result : public App::Scene
	{
	private:
		Cursor cursor[2];
	public:
		Result(const InitData& init);
		void update() override;
		void draw() const override;
	};
}

