#include "SceneData.hpp"

namespace game
{
	SceneData::SceneData()
	{
		this->newFighter = false;
		this->fighterNum = 0;
		for (int i = 0; i < 2; i++)
		{
			this->fighter[i] = Fighter();
		}
		this->winner = 0;
	}
}
