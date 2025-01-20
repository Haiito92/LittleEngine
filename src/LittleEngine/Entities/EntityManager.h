#pragma once
#include "API.h"

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

        
    };
}

