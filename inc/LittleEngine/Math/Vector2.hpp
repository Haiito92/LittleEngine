// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once
#include <LittleEngine/Math/Arithmetic.hpp>

namespace Le
{
    template<Arithmetic T>
    struct Vector2
    {
    public:
        constexpr Vector2();
        constexpr Vector2(T x, T y);
        
        T x;
        T y;
    };
    
    using Vector2f = Vector2<float>;
    using Vector2i = Vector2<int>;
}


#include <LittleEngine/Math/Vector2.inl>
