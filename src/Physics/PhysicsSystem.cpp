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
            bodyComponent->SetPos(bodyComponent->GetPos() + Vec2f::down * 10.0f * inDeltaTime);
        }
    }

    std::shared_ptr<BodyComponent> PhysicsSystem::CreateBody(const Vec2f& pos)
    {
        std::shared_ptr<BodyComponent> bodyComponent = std::make_shared<BodyComponent>(pos);
        AddBody(bodyComponent);
        return bodyComponent;
    }

    void PhysicsSystem::AddBody(const std::shared_ptr<BodyComponent>& inBodyComponent)
    {
        m_bodyComponents.push_back(inBodyComponent);
    }
}

