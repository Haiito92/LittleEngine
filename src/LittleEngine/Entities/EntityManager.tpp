#pragma once
#include <iostream>
#include <memory>

#include "Component.h"
#include "Core/Reflection/TypeRegistry.h"

namespace LittleEngine
{
    template <typename T>
    std::shared_ptr<T> EntityManager::CreateComponent(const int inArrayIndex)
    {
        std::shared_ptr<T> createdComponent = std::make_shared<T>();

        if(std::dynamic_pointer_cast<std::shared_ptr<Component>>(createdComponent) == nullptr) return nullptr;
        
        int componentTypeIndex = TypeRegistry::GetTypeIndex<T>();

        //If superior to componentsVectors size, means there is no vector for this component yet
        if(componentTypeIndex >= m_componentVectors.size())
        {
            //Add a new vector of type T
            // std::shared_ptr<std::vector<std::shared_ptr<T>>> tVector =
                m_componentVectors.emplace_back(std::make_shared<std::vector<std::shared_ptr<T>>>(m_entities.size(), nullptr));

            // tVector[inArrayIndex] = createdComponent;
            return createdComponent;
        }

        //Else get the vector with at the index corresponding to the componentTypeIndex
        std::shared_ptr<std::vector<T>> tVector = m_componentVectors[componentTypeIndex];
        tVector[inArrayIndex] = createdComponent;
        
        return createdComponent;
    }
    template <typename T>
    void EntityManager::AddComponent(std::shared_ptr<Entity> inOutEntity)
    {
        
        std::shared_ptr<T> createdComponent = CreateComponent<T>(inOutEntity->arrayIndex);
        if(createdComponent == nullptr) return;
        // inOutEntity->components.push_back(createdComponent);
    }
}
