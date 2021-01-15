#include "Debug.hpp"


#ifdef _DEBUG
namespace game
{
	void Debug(std::string str)
	{
		std::ofstream out("./data/Debug.txt");
		if (out.is_open())
		{
			out << str;
		}
		else
		{
			return;
		}

		out.close();
	}
}
#else
namespace game
{
	void Debug(std::string str)
	{
	}
}
#endif // DEBUG