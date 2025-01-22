#include "PhysicsSystem.h"

#include <iostream>
#include <memory>

#include "Collision/ShapeComponents/CircleComponent.h"
#include "Entities/EntityManager.h"
#include "Entities/Components/TransformComponent.h"

namespace LittleEngine
{
    void PhysicsSystem::SystemInitialization(std::shared_ptr<EntityManager>& inEntityManager)
    {
        System::SystemInitialization(inEntityManager);

        std::shared_ptr<Entity> entity = inEntityManager->CreateEntity();
        inEntityManager->AddComponent<TransformComponent>(entity);
    }

    void PhysicsSystem::SystemUpdate(std::shared_ptr<EntityManager>& inEntityManager)
    {
        System::SystemUpdate(inEntityManager);
        
    }

    void PhysicsSystem::Init()
    {
        std::cout << "Init Physics" <<'\n';
    }

    void PhysicsSystem::Update(float inDeltaTime, SDL_Window* inWindow) const
    {
        //For old systems
        // for (const std::shared_ptr<BodyComponent>& bodyComponent : m_bodyComponents)
        // {
        //     if(bodyComponent->mass <= 0) continue;
        //     
        //     //Reset force & calculate new force
        //     bodyComponent->force = Vec2f::ZERO;
        //     bodyComponent->force += m_gravity;
        //     
        //     //Calculate acceleration
        //     Vec2f acceleration = bodyComponent->force / bodyComponent->mass; //replace this with body mass later
        //     
        //     //Calculate linear velocity
        //     bodyComponent->linearVelocity = bodyComponent->linearVelocity + acceleration * inDeltaTime;
        //     std::cout << bodyComponent->linearVelocity.y <<'\n';
        //
        //     //Calculate position
        //     bodyComponent->pos = bodyComponent->pos + bodyComponent->linearVelocity * inDeltaTime;
        // }

        // CollisionsWithWindow(inWindow);
        
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
            const float radius = bodyComponent->circleShape->m_radius;
            Vec2f& pos = bodyComponent->pos;
            
            if(pos.x - radius < 0)
            {
                pos.x = 0 + radius;

                //Add Impact Vector
                bodyComponent->linearVelocity.x += bodyComponent->linearVelocity.x * -2.0f;
            }
            if(pos.x + radius > wWindow)
            {
                pos.x = wWindow - radius;

                //Add Impact Vector
                bodyComponent->linearVelocity.x += bodyComponent->linearVelocity.x * -2.0f;
            }
            if(pos.y - radius < 0)
            {
                pos.y = 0 + radius;

                //Add Impact Vector
                bodyComponent->linearVelocity.y += bodyComponent->linearVelocity.y * -2.0f;
            }
            if(pos.y + radius > hWindow)
            {
                pos.y = hWindow - radius;
                
                //Add Impact Vector
                bodyComponent->linearVelocity.y += bodyComponent->linearVelocity.y * -2.0f;
            }
            
        }
    }
}

