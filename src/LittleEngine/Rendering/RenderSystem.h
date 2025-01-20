#pragma once
#include "API.h"
#include <memory>
#include <vector>
#include <SDL_render.h>
namespace LittleEngine
{
    struct BodyComponent;

    class LE_RENDERING_API RenderSystem
    {
    public:
        RenderSystem() = default;
        RenderSystem(SDL_Renderer* inRenderer, SDL_Window* inWindow): m_renderer(inRenderer), m_window(inWindow){} 
        RenderSystem(const RenderSystem& other) = delete;
        RenderSystem(RenderSystem&& other) = delete;
        ~RenderSystem() = default;

        RenderSystem& operator=(const RenderSystem& other) = delete;
        RenderSystem& operator=(RenderSystem&& other) = delete;

        void Init();
        void Update(float inDeltaTime, const std::vector<std::shared_ptr<BodyComponent>>& inBodyComponents);
    
    private:
        SDL_Renderer* m_renderer;
        SDL_Window* m_window;
    };
}

