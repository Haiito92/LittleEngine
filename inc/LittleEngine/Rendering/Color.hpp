// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once
#include <LittleEngine/Math/Arithmetic.hpp>

namespace Le
{
    template<Arithmetic T>
    struct Color    
    {
    public:
        constexpr Color();
        constexpr Color(T r, T g, T b, T a);
        
        T r;
        T g; 
        T b;
        T a;
    };
    
    using Colorf = Color<float>;
    using Colorui8 = Color<std::uint8_t>;
}

#include <LittleEngine/Rendering/Color.inl>
