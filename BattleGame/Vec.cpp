#include "Vec.hpp"

namespace game
{
    Vec::Vec()
    {
        this->x = 0;
        this->y = 0;
    }

    Vec::Vec(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Vec Vec::operator+(const Vec& a)
    {
        return Vec(this->x + a.x, this->y + a.y);
    }
    Vec Vec::operator-(const Vec& a)
    {
        return Vec(this->x - a.x, this->y - a.y);
    }
    Vec Vec::operator*(const Vec& a)
    {
        return Vec(this->x * a.x, this->y * a.y);
    }
    Vec Vec::operator/(const Vec& a)
    {
        return Vec(this->x / a.x, this->y / a.y);
    }

    Vec operator*(const int& k, const Vec& vec)
    {
        return Vec(k * vec.x, k * vec.y);
    }
    Vec operator*(const Vec& vec, const int& k)
    {
        return operator*(k, vec);
    }
}
