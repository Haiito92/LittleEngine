#pragma once
#include <iostream>

namespace LittleEngine
{
    template <typename T>
    std::shared_ptr<T> EntityManager::CreateComponent()
    {
        std::shared_ptr<T> createdComponent = std::make_shared<T>();
        if(std::shared_ptr<Component> component = std::dynamic_pointer_cast<Component>(createdComponent))
        {
            std::cout << "CreateComponent" <<'\n';
            return createdComponent;
        }
        else
        {
            std::cout << "N0CreateComponent" <<'\n';
            return nullptr;
        }
        return nullptr;
    }
    template <typename T>
    void EntityManager::AddComponent(std::shared_ptr<Entity> inOutEntity)
    {
        std::shared_ptr<T> createdComponent = CreateComponent<T>();
        if(createdComponent == nullptr) return;
        inOutEntity->components.push_back(createdComponent);
    }
}
