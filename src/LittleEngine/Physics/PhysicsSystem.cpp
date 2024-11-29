#include "PhysicsSystem.h"

#include <iostream>
#include <memory>

#include "Collision/ShapeComponents/CircleComponent.h"

namespace LE
{

    void PhysicsSystem::Init()
    {
        std::cout << "Init Physics" <<'\n';
    }

    void PhysicsSystem::Update(float inDeltaTime, SDL_Window* inWindow) const
    {
        for (const std::shared_ptr<BodyComponent>& bodyComponent : m_bodyComponents)
        {
            if(bodyComponent->m_mass <= 0) continue;
            
            //Reset force & calculate new force
            bodyComponent->m_force = Vec2f::zero;
            bodyComponent->m_force += m_gravity;
            
            //Calculate acceleration
            Vec2f acceleration = bodyComponent->m_force / bodyComponent->m_mass; //replace this with body mass later
            
            //Calculate linear velocity
            bodyComponent->m_linearVelocity = bodyComponent->m_linearVelocity + acceleration * inDeltaTime;
            std::cout << bodyComponent->m_linearVelocity.m_y <<'\n';

            //Calculate position
            bodyComponent->m_pos = bodyComponent->m_pos + bodyComponent->m_linearVelocity * inDeltaTime;
        }

        CollisionsWithWindow(inWindow);
        
    }

    std::shared_ptr<BodyComponent> PhysicsSystem::CreateBody(const BodyCreationSettings& inSettings)
    {
        std::shared_ptr<BodyComponent> bodyComponent = std::make_shared<BodyComponent>(inSettings);
        AddBody(bodyComponent);
        return bodyComponent;
    }

    const std::vector<std::shared_ptr<BodyComponent>>& PhysicsSystem::GetBodyComponents() const
    {
        return m_bodyComponents;
    }

    void PhysicsSystem::AddBody(const std::shared_ptr<BodyComponent>& inBodyComponent)
    {
        m_bodyComponents.push_back(inBodyComponent);
    }

    void PhysicsSystem::CollisionsWithWindow(SDL_Window* inWindow) const
    {
        //Collision with window
        int wWindow, hWindow;
        SDL_GetWindowSize(inWindow, &wWindow, &hWindow);
        for (const std::shared_ptr<BodyComponent>& bodyComponent : m_bodyComponents)
        {
            const float radius = bodyComponent->m_circleShape->m_radius;
            Vec2f& pos = bodyComponent->m_pos;
            
            if(pos.m_x - radius < 0)
            {
                pos.m_x = 0 + radius;

                //Add Impact Vector
                bodyComponent->m_linearVelocity.m_x += bodyComponent->m_linearVelocity.m_x * -2.0f;
            }
            if(pos.m_x + radius > wWindow)
            {
                pos.m_x = wWindow - radius;

                //Add Impact Vector
                bodyComponent->m_linearVelocity.m_x += bodyComponent->m_linearVelocity.m_x * -2.0f;
            }
            if(pos.m_y - radius < 0)
            {
                pos.m_y = 0 + radius;

                //Add Impact Vector
                bodyComponent->m_linearVelocity.m_y += bodyComponent->m_linearVelocity.m_y * -2.0f;
            }
            if(pos.m_y + radius > hWindow)
            {
                pos.m_y = hWindow - radius;
                
                //Add Impact Vector
                bodyComponent->m_linearVelocity.m_y += bodyComponent->m_linearVelocity.m_y * -2.0f;
            }
            
        }
    }
}

