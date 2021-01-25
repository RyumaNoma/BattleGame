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

		for (int i = 0; i < 5; i++)
		{
			this->skill[i] = i + 1;
		}

		this->name = "No Name";
	}

	std::string FighterData::toS() const
	{
		std::string str = "";

		//���O
		str += this->name + ',';

		// �F
		for (int i = 0; i < 7; i++)
		{
			std::ostringstream oss;
			oss << this->color[i].r << ',' << this->color[i].g << ',' << this->color[i].b << ',';
			str +=  oss.str();
		}

		// �Z
		for (int i = 0; i < 5; i++)
		{
			std::ostringstream oss;
			oss << this->skill[i] << ',';
			str += oss.str();
		}

		debug(str);
		return str;
	}

	FighterData FighterData::toO(const std::string& str)
	{
		// �t���O
		bool nameFlag = false;
		bool colorFlag = false;
		bool skillFlag = false;

		int ci = 0;
		int si = 0;
		int rgb = 0;
		std::string now;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ',')
			{
				// ���O
				if (!nameFlag)
				{
					this->name = now;
					nameFlag = true;
				}
				// �F
				else if (!colorFlag && ci < 7)
				{
					switch (rgb)
					{
					case 0:
						this->color[ci].r = atoi(toC(now));
						rgb++;
						break;
					case 1:
						this->color[ci].g = atoi(toC(now));
						rgb++;
						break;
					case 2:
						this->color[ci++].b = atoi(toC(now));
						rgb = 0;
						break;
					}
					if (ci == 7) colorFlag = true;
				}
				else if (!skillFlag)
				{
					this->skill[si++] = atoi(toC(now));
					if (si == 5) skillFlag = true;
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

	String FighterData::showS() const
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