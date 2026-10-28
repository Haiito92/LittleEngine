// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <cmath>
#include <numbers>
#include <vector>
#include <fmt/format.h>
#include <LittleEngine/SDLBackend/SDLRenderer.hpp>
#include <LittleEngine/SDLBackend/SDLWindow.hpp>
#include <SDL3/SDL_render.h>
#include <LittleEngine/Rendering/Vertex.hpp>

namespace Le
{
    
    SDLRenderer::SDLRenderer(const SDLWindow& windowImpl):
    m_renderer(nullptr)
    {
        m_renderer = SDL_CreateRenderer(windowImpl.GetSDLHandle(), nullptr);
        
        if (!m_renderer)
            throw std::runtime_error(fmt::format("SDL_CreateRenderer() failed: {}", SDL_GetError()));
        
    }

    SDLRenderer::~SDLRenderer()
    {
        if (m_renderer)
            SDL_DestroyRenderer(m_renderer);
    }

    void SDLRenderer::RenderLine(float x1, float y1, float x2, float y2)
    {
        SDL_RenderLine(m_renderer, x1, y1, x2, y2);
    }

    void SDLRenderer::RenderFillRect(float x, float y, float width, float height)
    {
        SDL_FRect rect {.x = x, .y = y, .w = width, .h = height};
        SDL_RenderFillRect(m_renderer, &rect);
    }

    void SDLRenderer::RenderCircle(float cx, float cy, float radius, int segments)
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

    void SDLRenderer::RenderGeometry(const std::vector<Vertex>& vertices, const std::vector<int>& indices)
    {
        if (vertices.empty())
        {
            throw std::runtime_error("Renderer::RenderGeometry() : vertices is empty");
        }
        
        std::vector<SDL_Vertex> sdlVertices;
        sdlVertices.reserve(vertices.size());
        
        for (const Vertex& vertex : vertices)
        {
            sdlVertices.push_back(SDL_Vertex{
                .position = SDL_FPoint{.x = vertex.x, .y = vertex.y},
                .color = SDL_FColor {.r = vertex.r, .g = vertex.g, .b = vertex.b, .a = vertex.a},
                .tex_coord = SDL_FPoint{.x = vertex.u, .y = vertex.v}
            });
        }
        
        if (!SDL_RenderGeometry(m_renderer, nullptr, sdlVertices.data(), static_cast<int>(sdlVertices.size()), indices.empty() ? nullptr : indices.data(), static_cast<int>(indices.size())))
            throw std::runtime_error(fmt::format("SDL_RenderGeometry() failed: {}", SDL_GetError()));
    }

    void SDLRenderer::Clear()
    {
        SDL_RenderClear(m_renderer);
    }

    void SDLRenderer::Present()
    {
        SDL_RenderPresent(m_renderer);
    }

    void SDLRenderer::SetRenderDrawColor(const uint8_t& r, const uint8_t& g, const uint8_t& b, const uint8_t& a)
    {
        SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
    }
}
