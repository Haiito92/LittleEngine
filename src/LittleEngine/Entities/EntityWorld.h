#pragma once
#include <memory>
#include <vector>

#include "API.h"

namespace LittleEngine
{
    class System;
    class EntityManager;
    
    class LE_ENTITIES_API EntityWorld
    {
    public:
        EntityWorld();
        EntityWorld(const EntityWorld& other) = delete;
        EntityWorld(EntityWorld&& other) = delete;
        ~EntityWorld() = default;

        EntityWorld& operator=(const EntityWorld& other) = delete;
        EntityWorld& operator=(EntityWorld&& other) = delete;

        void WorldUpdate(const float inDeltaTime);
        void WorldFixedUpdate(const float inFixedDeltaTime);
        void WorldRenderUpdate();
        
    private:
        std::shared_ptr<EntityManager> m_entityManager;

        std::vector<std::shared_ptr<System>> m_updateSystems;
        std::vector<std::shared_ptr<System>> m_fixedUpdateSystems;
        std::vector<std::shared_ptr<System>> m_renderUpdateSystems;
    };
}

