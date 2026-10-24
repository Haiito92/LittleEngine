// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <cstdint>
#include <LittleEngine/SDLBackend/Export.hpp>

#include "LittleEngine/Rendering/IRendererImpl.hpp"

struct SDL_Renderer;

namespace Le
{
    class SDLWindowImpl;

    class LE_SDLBACKEND_API SDLRendererImpl : public IRendererImpl 
    {
    public:
        SDLRendererImpl() = delete;
        SDLRendererImpl(const SDLWindowImpl& windowImpl);
        SDLRendererImpl(const SDLRendererImpl& other) = delete;
        SDLRendererImpl(SDLRendererImpl&& other) = delete;
        ~SDLRendererImpl() override;

        SDLRendererImpl& operator=(const SDLRendererImpl& other) = delete;
        SDLRendererImpl& operator=(SDLRendererImpl&& other) = delete;
        
        void RenderLine(float x1, float y1, float x2, float y2) override;
        void RenderFillRect(float x, float y, float width, float height) override;
        void RenderCircle(float cx, float cy, float radius, int segments) override;
        
        void Clear() override;
        void Present() override;
        
        void SetRenderDrawColor(const uint8_t& r, const uint8_t& g, const uint8_t& b, const uint8_t& a) override;
    private:
        SDL_Renderer* m_renderer;
    };
}

#include <LittleEngine/SDLBackend/SDLRendererImpl.inl>
