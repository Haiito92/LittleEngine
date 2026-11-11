// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <LittleEngine/Math/Arithmetic.hpp>

namespace Le
{
    template<Arithmetic T> struct Vector2;
    
    template<Arithmetic T>
    struct Rect    
    {
    public:
        constexpr Rect();
        constexpr Rect(const Vector2<T>& position, const Vector2<T>& size);
        constexpr Rect(T x, T y, T width, T height);
    
        Vector2<T> position;
        Vector2<T> size;
    };
    
    using Rectf = Rect<float>;
    using Recti = Rect<int>;
}

#include <LittleEngine/Math/Rect.inl>
