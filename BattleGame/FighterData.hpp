#pragma once

#include <Siv3D.hpp>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "Function.hpp"
#include "Debug.hpp"
#include "Fighter.hpp"

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
		String showS();

		void toData(const Fighter& fighter);
	};

	std::vector<FighterData> loadData(std::string fileName);
}

