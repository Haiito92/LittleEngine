// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <cstdint>
#include <LittleEngine/Renderer/Export.hpp>

struct SDL_Renderer;

namespace Le
{
    class Window;
    
    class LE_RENDERER_API Renderer    
    {
    public:
        Renderer() = delete;
        Renderer(const Window& window);
        Renderer(const Renderer& other) = delete;
        Renderer(Renderer&& other) = delete;
        ~Renderer();

        Renderer& operator=(const Renderer& other) = delete;
        Renderer& operator=(Renderer&& other) = delete;
        
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

#include <LittleEngine/Renderer/Renderer.inl>
