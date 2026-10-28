// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <cstdint>
#include <LittleEngine/SDLBackend/Export.hpp>

#include "LittleEngine/Rendering/IRenderer.hpp"

struct SDL_Renderer;

namespace Le
{
    class SDLWindow;

    class LE_SDLBACKEND_API SDLRenderer : public IRenderer 
    {
    public:
        SDLRenderer() = delete;
        SDLRenderer(const SDLWindow& windowImpl);
        SDLRenderer(const SDLRenderer& other) = delete;
        SDLRenderer(SDLRenderer&& other) = delete;
        ~SDLRenderer() override;

        SDLRenderer& operator=(const SDLRenderer& other) = delete;
        SDLRenderer& operator=(SDLRenderer&& other) = delete;
        
        void RenderLine(float x1, float y1, float x2, float y2) override;
        void RenderFillRect(float x, float y, float width, float height) override;
        void RenderCircle(float cx, float cy, float radius, int segments) override;
        void RenderGeometry(const std::vector<Vertex>& vertices, const std::vector<int>& indices) override;
        
        void Clear() override;
        void Present() override;
        
        void SetRenderDrawColor(const uint8_t& r, const uint8_t& g, const uint8_t& b, const uint8_t& a) override;
    private:
        SDL_Renderer* m_renderer;
    };
}

#include <LittleEngine/SDLBackend/SDLRenderer.inl>
