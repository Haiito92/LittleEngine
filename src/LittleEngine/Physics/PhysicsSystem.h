#pragma once
#include <SDL_video.h>
#include <vector>
#include "API.h"

#include "BodyComponent/BodyComponent.h"
#include "Entities/System.h"


namespace LittleEngine
{
    struct BodyComponent;
    
    class LE_PHYSICS_API PhysicsSystem : public System
    {
    public:
        PhysicsSystem() = delete;
        PhysicsSystem(const std::shared_ptr<EntityManager>& entityManager);
        PhysicsSystem(const PhysicsSystem& other) = delete;
        PhysicsSystem(PhysicsSystem&& other) = delete;
        ~PhysicsSystem() = default;

        PhysicsSystem& operator=(const PhysicsSystem& other) = delete;
        PhysicsSystem& operator=(PhysicsSystem&& other) = delete;

        void Init();
        void Update(float inDeltaTime, SDL_Window* inWindow) const;

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
        void CollisionsWithWindow(SDL_Window* inWindow) const;
#pragma endregion 
    };
}
