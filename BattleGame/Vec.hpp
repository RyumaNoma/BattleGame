#pragma once

namespace game
{
	class Vec
	{
	public:
		int x;
		int y;

		Vec();
		Vec(int x, int y);

		Vec operator+(const Vec& a);
		Vec operator-(const Vec& a);
		Vec operator*(const Vec& a);
		Vec operator/(const Vec& a);
	};

	Vec operator*(const int& k, const Vec& vec);
	Vec operator*(const Vec& vec, const int& k);
}