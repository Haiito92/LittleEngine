// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <cmath>
#include <numbers>
#include <vector>
#include <fmt/format.h>
#include <LittleEngine/SDLBackend/SDLRendererImpl.hpp>
#include <LittleEngine/SDLBackend/SDLWindowImpl.hpp>
#include <SDL3/SDL_render.h>

Le::SDLRendererImpl::SDLRendererImpl(const SDLWindowImpl& windowImpl):
m_renderer(nullptr)
{
    m_renderer = SDL_CreateRenderer(windowImpl.GetSDLHandle(), nullptr);
    
    if (!m_renderer)
        throw std::runtime_error(fmt::format("SDL_CreateRenderer() failed: {}", SDL_GetError()));
    
}

Le::SDLRendererImpl::~SDLRendererImpl()
{
    if (m_renderer)
        SDL_DestroyRenderer(m_renderer);
}

void Le::SDLRendererImpl::RenderLine(float x1, float y1, float x2, float y2)
{
    SDL_RenderLine(m_renderer, x1, y1, x2, y2);
}

void Le::SDLRendererImpl::RenderFillRect(float x, float y, float width, float height)
{
    SDL_FRect rect {.x = x, .y = y, .w = width, .h = height};
    SDL_RenderFillRect(m_renderer, &rect);
}

void Le::SDLRendererImpl::RenderCircle(float cx, float cy, float radius, int segments)
{
    SDL_FPoint center{.x = cx, .y = cy};
        
    std::vector<SDL_FPoint> points(segments + 1);
        
    float angle = std::numbers::pi_v<float> * 2.0f / segments;
        
    for (int i = 0; i <= segments; i++)
    {
        float pointAngle = angle * i;
        points[i].x = center.x + radius * std::cos(pointAngle);
        points[i].y = center.y + radius * std::sin(pointAngle);
    }
    
    SDL_RenderLines(m_renderer, points.data(), points.size());
}

void Le::SDLRendererImpl::Clear()
{
    SDL_RenderClear(m_renderer);
}

void Le::SDLRendererImpl::Present()
{
    SDL_RenderPresent(m_renderer);
}

void Le::SDLRendererImpl::SetRenderDrawColor(const uint8_t& r, const uint8_t& g, const uint8_t& b, const uint8_t& a)
{
    SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
}
