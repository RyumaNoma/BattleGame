#include "Function.hpp"

namespace game
{
	template<class ...Args>
	bool fLine(std::string fileName, const char* mode, const char& format, Args ...args)
	{
		FILE* out;
		fopen_s(&out, fileName, mode);

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
	bool fLine(std::string fileName, const char* mode, std::string str)
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