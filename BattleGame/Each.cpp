#include "Fighter.hpp"
#include "FighterData.hpp"

namespace game
{
	void toData(const Fighter& fighter, FighterData& fd)
	{
		for (int i = 0; i < 7; i++)
		{
			fd.color[i] = fighter.parts[i].color;
		}
		for (int i = 0; i < 5; i++)
		{
			fd.skill[i] = fighter.skill[i];
		}
	}

	void adaptData(Fighter& fighter, const FighterData& fd)
	{
		for (int i = 0; i < 7; i++)
		{
			fighter.parts[i].color = fd.color[i];
		}
		for (int i = 0; i < 5; i++)
		{
			fighter.skill[i] = fd.skill[i];
		}
	}
}