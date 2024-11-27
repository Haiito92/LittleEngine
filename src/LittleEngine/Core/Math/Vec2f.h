#pragma once
#include "API.h"

namespace LE
{
    struct LE_CORE_API Vec2f
    {
        Vec2f() = default;
        Vec2f(float x, float y):m_x(x),m_y(y){}
        Vec2f(const Vec2f& other):m_x(other.m_x),m_y(other.m_y){}
        Vec2f(Vec2f&& other) = delete;
        ~Vec2f() = default;

        Vec2f& operator=(const Vec2f& other) = default;
        Vec2f& operator=(Vec2f&& other) = default;

        Vec2f operator+(const Vec2f& other) const;
        Vec2f& operator+=(const Vec2f& other);
        
        Vec2f operator*(const float f) const;
        Vec2f operator/(const float f) const;

        float m_x = 0;
        float m_y = 0;

        static const Vec2f zero;
        static const Vec2f one;
        static const Vec2f up;
        static const Vec2f down;
        static const Vec2f left;
        static const Vec2f right;
    }; 
}

