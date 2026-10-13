// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <cstdint>
#include <LittleEngine/Platform/Export.hpp>

struct SDL_Renderer;

namespace Le
{
    class WindowImpl;

    class LE_PLATFORM_API RendererImpl    
    {
    public:
        RendererImpl() = delete;
        RendererImpl(const WindowImpl& windowImpl);
        RendererImpl(const RendererImpl& other) = delete;
        RendererImpl(RendererImpl&& other) = delete;
        ~RendererImpl();

        RendererImpl& operator=(const RendererImpl& other) = delete;
        RendererImpl& operator=(RendererImpl&& other) = delete;
        
        void RenderLine(float x1, float y1, float x2, float y2);
        void RenderFillRect(float x, float y, float width, float height);
        void RenderCircle(float cx, float cy, float radius, int segments);
        
        void Clear();
        void Present();
        
        void SetRenderDrawColor(const uint8_t& r, const uint8_t& g, const uint8_t& b, const uint8_t& a);
    private:
        SDL_Renderer* m_renderer;
    };
}

#include <LittleEngine/Platform/RendererImpl.inl>
