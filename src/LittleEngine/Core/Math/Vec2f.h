#pragma once
#include "API.h"

namespace LittleEngine
{
    struct LE_CORE_API Vec2f
    {
        Vec2f() = default;
        Vec2f(float x, float y):x(x),y(y){}
        Vec2f(const Vec2f& other):x(other.x),y(other.y){}
        Vec2f(Vec2f&& other) = delete;
        ~Vec2f() = default;

        Vec2f& operator=(const Vec2f& other) = default;
        Vec2f& operator=(Vec2f&& other) = default;

        Vec2f operator+(const Vec2f& other) const;
        Vec2f& operator+=(const Vec2f& other);
        
        Vec2f operator*(const float f) const;
        Vec2f operator/(const float f) const;

        float x = 0;
        float y = 0;

        static const Vec2f ZERO;
        static const Vec2f ONE;
        static const Vec2f UP;
        static const Vec2f DOWN;
        static const Vec2f LEFT;
        static const Vec2f RIGHT;
    }; 
}

