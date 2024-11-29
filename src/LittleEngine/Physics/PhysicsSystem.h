#pragma once
#include <SDL_video.h>
#include <vector>
#include "API.h"

#include "BodyComponent/BodyComponent.h"


namespace LE
{
    struct BodyComponent;
    
    class LE_PHYSICS_API PhysicsSystem
    {
    public:
        PhysicsSystem() = default;
        PhysicsSystem(const PhysicsSystem& other) = delete;
        PhysicsSystem(PhysicsSystem&& other) = delete;
        ~PhysicsSystem() = default;

        PhysicsSystem& operator=(const PhysicsSystem& other) = delete;
        PhysicsSystem& operator=(PhysicsSystem&& other) = delete;

        void Init();
        void Update(float inDeltaTime, SDL_Window* inWindow);

#pragma region Physical Bodies
        
    public:
        std::shared_ptr<BodyComponent> CreateBody(const BodyCreationSettings& inSettings);
        
        inline const std::vector<std::shared_ptr<BodyComponent>>& GetBodyComponents() const;
    private:
        void AddBody(const std::shared_ptr<BodyComponent>& inBodyComponent);

        std::vector<std::shared_ptr<BodyComponent>> m_bodyComponents;

        Vec2f m_gravity = {0, 9.81f};
        
#pragma endregion

#pragma region Collisions
        
#pragma endregion 
    };
}
