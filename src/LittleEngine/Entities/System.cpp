#include "System.h"

#include <memory>

#include "EntityManager.h"

namespace LittleEngine
{
    System::System(const std::shared_ptr<EntityManager>& entityManager) : m_entityManager(entityManager)
    {
        
    }
}

