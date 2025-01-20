#pragma once
#include <memory>
#include <vector>

#include "API.h"
#include "Entity.h"

namespace LittleEngine
{
    class LE_ENTITIES_API EntityManager
    {
    public:
        EntityManager() = default;
        EntityManager(const EntityManager& other) = delete;
        EntityManager(EntityManager&& other) = delete;
        ~EntityManager() = default;
        
        EntityManager& operator=(const EntityManager& other) = delete;
        EntityManager& operator=(EntityManager&& other) = delete;

        std::shared_ptr<Entity> CreateEntity();
        
    private:
        //This ?
        std::vector<std::shared_ptr<Entity>> m_entities;
        //Or this ?
        //std::vector<Entity> m_entities;
        
    };
}

