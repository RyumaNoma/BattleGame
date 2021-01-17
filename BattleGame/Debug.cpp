#include "Debug.hpp"

#ifdef _DEBUG
namespace game
{
	void debugReset(void)
	{
		FILE* out;
		fopen_s(&out, "./data/Debug.txt", "w");
		if (out)
		{
			fclose(out);
		}
	}

	void debug(const char* tag, const int& value)
	{
		fLine("./data/DEbug.txt", tag, value);
	}
}
#else
namespace game
{
	void debugReset(void)
	{
	}
	void debug(const char* format, const int& value)
	{
	}
}
#endif