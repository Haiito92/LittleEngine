#include "EntityManager.h"

#include <memory>
#include <memory>

namespace LittleEngine
{
    std::shared_ptr<Entity> EntityManager::CreateEntity()
    {
        // Version for when I used vector<Entity> instead of vector<std::shared_ptr<Entity>>, aka using raw strut instead of shared_ptr
        // return std::shared_ptr<Entity>(&m_entities.emplace_back());
        std::shared_ptr<Entity> newEntity = m_entities.emplace_back(std::make_shared<Entity>(m_entities.size()));

        for(std::shared_ptr<std::vector<std::shared_ptr<Component>>> componentVector : m_componentVectors)
        {
            componentVector->push_back(nullptr);
        }
        
        return newEntity;
    }
}

