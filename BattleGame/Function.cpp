#include "Function.hpp"

namespace game
{
	template<class ...Args>
	bool addLine(std::string fileName, const char& format, Args ...args)
	{
		FILE* out;
		fopen_s(&out, fileName, "a+");
		
		if (out)
		{
			fprintf_s(out, format, args...);
			return true;
		}
		else
		{
			return false;
		}
	}

	template<class ...Args>
	bool writeLine(std::string fileName, const char& format, Args ...args)
	{
		FILE* out;
		fopen_s(&out, fileName, "w");

		if (out)
		{
			fprintf_s(out, format, args...);
			return true;
		}
		else
		{
			return false;
		}
	}
}