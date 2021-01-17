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

	std::string FighterData::toS()
	{
		std::string str;

		// 色
		for (int i = 0; i < 7; i++)
		{
			std::string color;
			if (this->color[i] == Palette::Black)
			{
				color = "Black";
			}
			else if (this->color[i] == Palette::Gray)
			{
				color = "Gray";
			}
			else if (this->color[i] == Palette::Red)
			{
				color = "Red";
			}
			else if (this->color[i] == Palette::Yellow)
			{
				color = "Yellow";
			}
			else if (this->color[i] == Palette::Purple)
			{
				color = "Purple";
			}
			else if (this->color[i] == Palette::Green)
			{
				color = "Green";
			}
			else if (this->color[i] == Palette::Blue)
			{
				color = "Blue";
			}
			
			str += color + ',';
		}

		//名前
		str += this->name + ',';

		return str;
	}

	FighterData FighterData::toO(const std::string& str)
	{
		int i = 0;
		// 色
		int ci = 0;
		std::string now;

		while (str[i])
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
				}
			}
			else
			{
				now += str[i];
			}
		}

		return (*this);
	}

	std::vector<FighterData> loadData(std::string fileName)
	{
		std::ifstream in(fileName);
		std::vector<FighterData> ret;
		
		if (in.is_open())
		{
			std::string line;
			while (getline(in, line))
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