#include "EntityWorld.h"

#include <memory>
#include <memory>
#include <memory>
#include "EntityManager.h"
#include "System.h"
#include "Physics/PhysicsSystem.h"

namespace LittleEngine
{
    EntityWorld::EntityWorld()
    {
        m_entityManager = std::make_shared<EntityManager>();

        //InitSystems
        std::shared_ptr<PhysicsSystem> tPhysicsSystem = std::static_pointer_cast<PhysicsSystem>(m_fixedUpdateSystems.emplace_back(std::make_shared<PhysicsSystem>()));

        tPhysicsSystem->SystemInitialization(m_entityManager);
    }

    void EntityWorld::WorldUpdate(const float inDeltaTime)
    {
        for(std::shared_ptr<System> updateSystem : m_updateSystems)
        {
            updateSystem->SystemUpdate(m_entityManager);
        }
    }

    void EntityWorld::WorldFixedUpdate(const float inFixedDeltaTime)
    {
        for(std::shared_ptr<System> fixedUpdateSystem : m_fixedUpdateSystems)
        {
            fixedUpdateSystem->SystemUpdate(m_entityManager);
        }
    }

    void EntityWorld::WorldRenderUpdate()
    {
        for(std::shared_ptr<System> renderUpdateSystem : m_renderUpdateSystems)
        {
            renderUpdateSystem->SystemUpdate(m_entityManager);
        }
    }
}

