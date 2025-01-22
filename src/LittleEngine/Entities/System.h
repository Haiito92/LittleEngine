#pragma once
#include <memory>

#include "API.h"

namespace LittleEngine
{
    class EntityManager;

    class LE_ENTITIES_API System
    {
    public:
        System() = default;
        System(const System& other) = delete;
        System(System&& other) = delete;
        virtual ~System() = default;

        System& operator=(const System& other) = delete;
        System& operator=(System&& other) = delete;

        void virtual SystemInitialization(std::shared_ptr<EntityManager>& inEntityManager);
        void virtual SystemUpdate(std::shared_ptr<EntityManager>& inEntityManager);
    }; 
}

