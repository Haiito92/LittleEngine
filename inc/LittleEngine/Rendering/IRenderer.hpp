// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <vector>
#include <LittleEngine/Rendering/Export.hpp>
#include <LittleEngine/Math/Vector2.hpp>
#include <LittleEngine/Math/Rect.hpp>
#include <LittleEngine/Rendering/Color.hpp>

namespace Le
{
    struct Vertex;

    class LE_RENDERING_API IRenderer    
    {
    public:
        virtual ~IRenderer();
        
        virtual void RenderLine(const Vector2f& start, const Vector2f& end) = 0;
        virtual void RenderFillRect(const Rectf& rect) = 0;
        virtual void RenderCircle(const Vector2f& centerPos, float radius, int segments) = 0;
        virtual void RenderGeometry(const std::vector<Vertex>& vertices, const std::vector<int>& indices) = 0;
        
        virtual void Clear() = 0;
        virtual void Present() = 0;
        
        virtual void SetRenderDrawColor(const Colorui8& color) = 0;
    };
}
