#include "RenderSystem.h"

#include <memory>
#include <SDL2_gfxPrimitives.h>

#include "Physics/BodyComponent/BodyComponent.h"
#include "Physics/Collision/ShapeComponents/CircleComponent.h"

namespace LE
{
    void RenderSystem::Init()
    {
    }

    void RenderSystem::Update(float inDeltaTime, const std::vector<std::shared_ptr<BodyComponent>>& inBodyComponents)
    {
        //Clear screen
        SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00,0x00,0xFF);
        SDL_RenderClear(m_renderer);

        int width, height;
        SDL_GetWindowSize(m_window, &width, &height);

        for (std::shared_ptr<BodyComponent> bodyComponent : inBodyComponents)
        {
            //Draw Body
            
            filledCircleRGBA(m_renderer,
                bodyComponent->m_pos.m_x,
                bodyComponent->m_pos.m_y,
                bodyComponent->m_circleShape->m_radius,
                255,255,255,255);
        }
            
        //Update screen
        SDL_RenderPresent(m_renderer);
        
    }
}
