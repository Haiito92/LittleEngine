#pragma once
#include <memory>

#include "API.h"

namespace LittleEngine
{
    class EntityManager;

    class LE_ENTITIES_API System
    {
    public:
        System() = delete;
        System(const std::shared_ptr<EntityManager>& entityManager);
        System(const System& other) = delete;
        System(System&& other) = delete;
        ~System() = default;

        System& operator=(const System& other) = delete;
        System& operator=(System&& other) = delete;

    protected:
        std::shared_ptr<EntityManager> m_entityManager;
    }; 
}

