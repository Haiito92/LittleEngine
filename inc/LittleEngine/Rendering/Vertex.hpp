// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <LittleEngine/Rendering/Export.hpp>
#include <LittleEngine/Math/Vector2.hpp>
#include <LittleEngine/Rendering/Color.hpp>

namespace Le
{
    struct LE_RENDERING_API Vertex    
    {
    public:
        Vector2f position;
        Colorf color;
        Vector2f uv;
    };
}

#include <LittleEngine/Rendering/Vertex.inl>
