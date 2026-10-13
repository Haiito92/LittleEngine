// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <numbers>
#include <vector>
#include <LittleEngine/Renderer/Renderer.hpp>
#include <LittleEngine/Core/Platform/Window.hpp>
#include <SDL3/SDL.h>
#include <fmt/printf.h>

Le::Renderer::Renderer(const Window& window):
m_renderer(nullptr)
{
    m_renderer = SDL_CreateRenderer(window.GetHandle(), nullptr);
    
    if (!m_renderer) fmt::printf("SDL_CreateRenderer() failed: {}", SDL_GetError());
}

Le::Renderer::~Renderer()
{
    if (m_renderer)
    {
        SDL_DestroyRenderer(m_renderer);
    }
}

void Le::Renderer::RenderLine(float x1, float y1, float x2, float y2)
{
    SDL_RenderLine(m_renderer, x1, y1, x2, y2);
}

void Le::Renderer::RenderFillRect(float x, float y, float width, float height)
{
    SDL_FRect rect {.x = x, .y = y, .w = width, .h = height};
    SDL_RenderFillRect(m_renderer, &rect);
}

void Le::Renderer::RenderCircle(float cx, float cy, float radius, int segments)
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

void Le::Renderer::Clear()
{
    SDL_RenderClear(m_renderer);
}

void Le::Renderer::Present()
{
    SDL_RenderPresent(m_renderer);
}

void Le::Renderer::SetRenderDrawColor(const uint8_t& r, const uint8_t& g, const uint8_t& b, const uint8_t& a)
{
    SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
}
