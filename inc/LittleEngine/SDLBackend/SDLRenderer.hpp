// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <cstdint>
#include <LittleEngine/SDLBackend/Export.hpp>
#include <LittleEngine/Rendering/IRenderer.hpp>
#include <LittleEngine/Math/Rect.hpp>
#include <LittleEngine/Math/Vector2.hpp>

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
        
        void RenderLine(const Vector2f& start, const Vector2f& end) override;
        void RenderFillRect(const Rectf& rect) override;
        void RenderCircle(const Vector2f& centerPos, float radius, int segments) override;
        void RenderGeometry(const std::vector<Vertex>& vertices, const std::vector<int>& indices) override;
        
        void Clear() override;
        void Present() override;
        
        void SetRenderDrawColor(const Colorui8& color) override;
    private:
        SDL_Renderer* m_renderer;
    };
}

#include <LittleEngine/SDLBackend/SDLRenderer.inl>
