#pragma once

#include "Fighter.hpp"

namespace game
{
	class SceneData
	{
	public:
		bool newFighter;
		int fighterNum;
		Fighter fighter[2];
		int winner;

		SceneData();
	};
}