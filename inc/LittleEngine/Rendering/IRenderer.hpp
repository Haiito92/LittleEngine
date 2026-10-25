// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <cstdint>
#include <LittleEngine/Rendering/Export.hpp>

namespace Le
{
    class LE_RENDERING_API IRenderer    
    {
    public:
        virtual ~IRenderer();
        
        virtual void RenderLine(float x1, float y1, float x2, float y2) = 0;
        virtual void RenderFillRect(float x, float y, float width, float height) = 0;
        virtual void RenderCircle(float cx, float cy, float radius, int segments) = 0;
        
        virtual void Clear() = 0;
        virtual void Present() = 0;
        
        virtual void SetRenderDrawColor(const std::uint8_t& r, const uint8_t& g, const uint8_t& b, const uint8_t& a) = 0;
    };
}
