#pragma once
#include <vector>
#include "../API.h"

#include "BodyComponent.h"


namespace LE
{
    struct BodyComponent;
    
    class LE_Physics_API PhysicsSystem
    {
    public:
        PhysicsSystem() = default;
        PhysicsSystem(const PhysicsSystem& other) = delete;
        PhysicsSystem(PhysicsSystem&& other) = delete;
        ~PhysicsSystem() = default;

        PhysicsSystem& operator=(const PhysicsSystem& other) = delete;
        PhysicsSystem& operator=(PhysicsSystem&& other) = delete;

        void Init();
        void Update(float inDeltaTime);

        std::shared_ptr<BodyComponent> CreateBody(const Vec2f& pos);
    private:
        void AddBody(const std::shared_ptr<BodyComponent>& inBodyComponent);

        std::vector<std::shared_ptr<BodyComponent>> m_bodyComponents;
    };
}
