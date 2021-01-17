#include "Each.hpp"

namespace game
{
	void toData(const Fighter& fighter, FighterData& fd)
	{
		for (int i = 0; i < 7; i++)
		{
			fd.color[i] = fighter.parts[i].color;
		}
	}

	void adaptData(Fighter& fighter, const FighterData& fd)
	{
		for (int i = 0; i < 7; i++)
		{
			fighter.parts[i].color = fd.color[i];
		}
	}
}