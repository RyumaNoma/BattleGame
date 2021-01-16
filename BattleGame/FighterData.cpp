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
	}

	char* FighterData::toS()
	{
		// êF
		char str[10000];
		for (int i = 0; i < 7; i++)
		{
			char color[100];
			if (this->color[i] == Palette::Black)
			{
				strcpy(color, "Black");
			}
			else if (this->color[i] == Palette::Gray)
			{
				strcpy(color, "Gray");
			}
			else if (this->color[i] == Palette::Red)
			{
				strcpy(color, "Red");
			}
			else if (this->color[i] == Palette::Yellow)
			{
				strcpy(color, "Yellow");
			}
			else if (this->color[i] == Palette::Purple)
			{
				strcpy(color, "Purple");
			}
			else if (this->color[i] == Palette::Green)
			{
				strcpy(color, "Green");
			}
			else if (this->color[i] == Palette::Blue)
			{
				strcpy(color, "Blue");
			}
			sprintf(str, "%s,", color);
		}

		return str;
	}

	FighterData FighterData::toO(const std::string& str)
	{
		int i = 0;
		// êF
		int ci = 0;
		std::string now;

		while (str[i])
		{
			if (str[i] == ',')
			{
				// êF
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

	
}