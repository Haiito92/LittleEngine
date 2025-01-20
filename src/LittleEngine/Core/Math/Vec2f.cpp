#include "Vec2f.h"


namespace LittleEngine
{
    Vec2f Vec2f::operator+(const Vec2f& other) const
    {
        return {x + other.x, y + other.y};
    }

    Vec2f& Vec2f::operator+=(const Vec2f& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2f Vec2f::operator*(const float f) const
    {
        return {x*f, y*f};
    }

    Vec2f Vec2f::operator/(const float f) const
    {
        return {x/f, y/f};
    }

    const Vec2f Vec2f::ZERO = {0,0};
    const Vec2f Vec2f::ONE = {1,1};
    const Vec2f Vec2f::UP = {0,-1};
    const Vec2f Vec2f::DOWN = {0,1};
    const Vec2f Vec2f::LEFT = {-1,0};
    const Vec2f Vec2f::RIGHT = {1,0};

}

