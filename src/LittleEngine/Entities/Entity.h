#pragma once
#include <memory>
#include <vector>
#include "API.h"


namespace LittleEngine
{
    struct Component;

    struct LE_ENTITIES_API Entity
    {
    public:
        Entity() = delete;
        Entity(const int inArrayIndex);
        Entity(const Entity& other) = delete;
        Entity(Entity&& other) = delete;
        ~Entity() = default;

        Entity& operator=(const Entity& other) = delete;
        Entity& operator=(Entity&& other) = delete;

        //This is better ?
        // std::vector<std::shared_ptr<Component>> components;
        //Or this is better ?
        // std::vector<Component> components;

        int arrayIndex;
    };
}

