#pragma once

#include <Siv3D.hpp>
#include <string>

namespace game
{
	class FighterData
	{
	public:
		Color color[7];
		std::string name;

		FighterData();
		std::string toS();
		FighterData toO(const std::string& str);
	};
}

