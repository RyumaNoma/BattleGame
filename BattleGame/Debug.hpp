#pragma once

#include <fstream>
#include <utility>
#include <cstdio>

#ifdef _DEBUG
namespace game
{
	void debugReset(void)
	{
		FILE* out;
		fopen_s(&out, "./data/Debug.txt", "w");
		fclose(out);
	}

	template <class... Args>
	void debug(const char* format, const Args& ...args)
	{
		FILE* out;
		fopen_s(&out, "./data/Debug.txt", "a");
		if (out)
		{
			fprintf(out, format, args...);
			fclose(out);
		}
	}
}
#else
namespace game
{
	void debugReset(void)
	{
	}
	template <class... Args>
	void debug(const char* format, const Args& ...args)
	{
	}
}
#endif