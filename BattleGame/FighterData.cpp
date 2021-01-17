#include "FighterData.hpp"

namespace game
{
	FighterData::FighterData()
	{
		this->color[0] = Palette::Black;
		this->color[1] = Palette::Red;
		this->color[2] = Palette::Blue;
		this->color[3] = Palette::Yellow;
		this->color[4] = Palette::Green;
		this->color[5] = Palette::Purple;
		this->color[6] = Palette::Gray;

		this->name = "No Name";
	}

	String FighterData::toS()
	{
		String str;

		//名前
		str += Unicode::Widen(this->name + ',');

		// 色
		for (int i = 0; i < 7; i++)
		{
			String color;
			if (this->color[i] == Palette::Black)
			{
				color = U"Black";
			}
			else if (this->color[i] == Palette::Gray)
			{
				color = U"Gray";
			}
			else if (this->color[i] == Palette::Red)
			{
				color = U"Red";
			}
			else if (this->color[i] == Palette::Yellow)
			{
				color = U"Yellow";
			}
			else if (this->color[i] == Palette::Purple)
			{
				color = U"Purple";
			}
			else if (this->color[i] == Palette::Green)
			{
				color = U"Green";
			}
			else if (this->color[i] == Palette::Blue)
			{
				color = U"Blue";
			}
			
			str += color + ',';
		}

		return str;
	}

	FighterData FighterData::toO(const std::string& str)
	{
		// 色
		int ci = 0;
		std::string now;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ',')
			{
				// 色
				if (ci < 7)
				{
					if (now == "Black")
					{
						this->color[ci++] = Palette::Black;
					}
					else if (now == "Gray")
					{
						this->color[ci++] = Palette::Gray;
					}
					else if (now == "Red")
					{
						this->color[ci++] = Palette::Red;
					}
					else if (now == "Yellow")
					{
						this->color[ci++] = Palette::Yellow;
					}
					else if (now == "Purple")
					{
						this->color[ci++] = Palette::Purple;
					}
					else if (now == "Green")
					{
						this->color[ci++] = Palette::Green;
					}
					else if (now == "Blue")
					{
						this->color[ci++] = Palette::Blue;
					}
					// 名前
					else
					{
						this->name = now;
					}
				}

				now = "";
			}
			else
			{
				now += str[i];
			}
		}

		return (*this);
	}

	String FighterData::showS()
	{
		String str;

		str += Unicode::Widen(this->name);

		return str;
	}

	std::vector<FighterData> loadData(std::string fileName)
	{
		std::ifstream in(fileName);
		std::vector<FighterData> ret;
		
		if (in.is_open())
		{
			std::string line;
			while (std::getline(in, line))
			{
				FighterData fd;
				fd.toO(line);
				ret.push_back(fd);
			}
			in.close();
		}

		return ret;
	}
}