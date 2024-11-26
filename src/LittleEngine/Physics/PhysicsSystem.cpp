#include "PhysicsSystem.h"

#include <cstdio>
#include <iostream>
#include <memory>
#include <string>

namespace LE
{

    void PhysicsSystem::Init()
    {
        std::cout << "Init Physics" <<'\n';
    }

    void PhysicsSystem::Update(float inDeltaTime)
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
}

