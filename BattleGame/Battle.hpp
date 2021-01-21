#pragma once

#include <Siv3D.hpp>
#include "SceneData.hpp"
#include "Fighter.hpp"
#include"Motion.hpp"
#include "Direction.hpp"
#include "FighterState.hpp"
#include "Debug.hpp"
#include "BodyPart.hpp"

namespace game
{
	using App = SceneManager<int, SceneData>;
	class Battle : public App::Scene
	{
	private:
		Fighter fighter[2];
		int fighterX[2];
		int fighterY[2];
	public:
		Battle(const InitData& init);
		void update() override;
		void draw() const override;

		bool isHit(int from, int to);

		void inField();
	};
}

