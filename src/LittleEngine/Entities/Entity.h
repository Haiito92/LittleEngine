#pragma once
#include <vector>
#include "API.h"
#include "Component.h"

namespace LittleEngine
{
    struct LE_ENTITIES_API Entity
    {
    public:
        Entity() = default;
        Entity(const Entity& other) = delete;
        Entity(Entity&& other) = delete;
        ~Entity() = default;

        Entity& operator=(const Entity& other) = delete;
        Entity& operator=(Entity&& other) = delete;
        
        std::vector<Component> components;
    };
}

