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

    void SDLRenderer::RenderLine(const Vector2f& start, const Vector2f& end)
    {
        SDL_RenderLine(m_renderer, start.x, start.y, end.x, end.y);
    }

    void SDLRenderer::RenderFillRect(const Rectf& rect)
    {
        SDL_FRect sdlRect {.x = rect.position.x, .y = rect.position.y, .w = rect.size.x, .h = rect.size.y};
        SDL_RenderFillRect(m_renderer, &sdlRect);
    }

    void SDLRenderer::RenderCircle(const Vector2f& centerPos, float radius, int segments)
    {
        SDL_FPoint center{.x = centerPos.x, .y = centerPos.y};
            
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
        
        for (const Vertex& v : vertices)
        {
            sdlVertices.push_back(SDL_Vertex{
                .position = SDL_FPoint{.x = v.position.x, .y = v.position.y},
                .color = SDL_FColor {.r = v.color.r, .g = v.color.g, .b = v.color.b, .a = v.color.a},
                .tex_coord = SDL_FPoint{.x = v.uv.x, .y = v.uv.y}
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

    void SDLRenderer::SetRenderDrawColor(const Colorui8& color)
    {
        SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    }
}
