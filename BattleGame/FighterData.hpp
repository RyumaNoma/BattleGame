#pragma once

#include <Siv3D.hpp>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

namespace game
{
	class FighterData
	{
	public:
		Color color[7];
		std::string name;

		FighterData();
		String toS();
		FighterData toO(const std::string& str);
		String showS();
	};

	std::vector<FighterData> loadData(std::string fileName);
}

