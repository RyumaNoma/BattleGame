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

	template<class ...Args>
	bool fLine(const std::string& fileName, const char* mode, const char& format, Args ...args)
	{
		FILE* out;
		fopen_s(&out, toC(fileName), mode);

		if (out)
		{
			fprintf_s(out, format, args...);
			fclose(out);
			return true;
		}
		else
		{
			return false;
		}
	}

	template<class ...Args>
	bool fLine(const std::string& fileName, const char* mode, std::string str)
	{
		std::ofstream out(fileName, mode);

		if (out.is_open())
		{
			out << str;
			out.close();
			return true;
		}
		else
		{
			return false;
		}
	}
}