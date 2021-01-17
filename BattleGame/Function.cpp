#include "Function.hpp"

namespace game
{
	char* toC(const std::string& str)
	{
		char out[1000];
		for (int i = 0; i < str.size(); i++)
		{
			out[i] = str[i];
		}
		out[str.size()] = '\0';

		return out;
	}

	bool fLine(const std::string& fileName, const std::string& str)
	{
		std::ofstream out(fileName, std::ios_base::out | std::ios_base::app);

		if (out.is_open())
		{
			out << str << std::endl;
			out.close();
			return true;
		}
		else
		{
			return false;
		}
	}

	bool fLine(const std::string& fileName, const char* str)
	{
		std::ofstream out(fileName, std::ios_base::out | std::ios_base::app);

		if (out.is_open())
		{
			out << str << std::endl;
			out.close();
			return true;
		}
		else
		{
			return false;
		}
	}

	bool fLine(const std::string& fileName, const char* tag, const int& value)
	{
		std::ofstream out(fileName, std::ios_base::out | std::ios_base::app);

		if (out.is_open())
		{
			out << tag << " : " << value << std::endl;;
			out.close();
			return true;
		}
		else
		{
			return false;
		}
	}
}