// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <LittleEngine/Rendering/Export.hpp>

namespace Le
{
    struct LE_RENDERING_API Vertex    
    {
    public:
        float x, y;
        float r, g, b, a;
        float u, v;
    };
}

#include <LittleEngine/Rendering/Vertex.inl>
