#include "Vec2f.h"


namespace LE
{
    Vec2f::Vec2f(float x, float y):
    m_x(x),m_y(y)
    {
        
    }

    Vec2f::Vec2f(const Vec2f& other):
    m_x(other.m_x),m_y(other.m_y)
    {
        
    }

    Vec2f& Vec2f::operator+(const Vec2f& other)
    {
        m_x += other.m_x;
        m_y += other.m_y;
        return *this;
    }

    Vec2f& Vec2f::operator*(float f)
    {
        m_x *= f;
        m_y *= f;
        return *this;
    }

    Vec2f Vec2f::operator*(float f) const
    {
        return {m_x*f, m_y*f};
    }

    const Vec2f Vec2f::zero = {0,0};
    const Vec2f Vec2f::one = {1,1};
    const Vec2f Vec2f::up = {0,-1};
    const Vec2f Vec2f::down = {0,1};
    const Vec2f Vec2f::left = {-1,0};
    const Vec2f Vec2f::right = {1,0};

}

