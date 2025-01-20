#pragma once
#include "API.h"

namespace LittleEngine
{
    struct LE_ENTITIES_API Component
    {
    public:
        Component() = default;
        Component(const Component& other) = delete;
        Component(Component&& other) = delete;
        ~Component() = default;

        Component& operator=(const Component& other) = delete;
        Component& operator=(Component&& other) = delete;
    };
}

