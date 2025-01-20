#pragma once
#include "API.h"

namespace LittleEngine
{
    struct LE_ENTITIES_API System
    {
    public:
        System() = default;
        System(const System& other) = delete;
        System(System&& other) = delete;
        ~System() = default;

        System& operator=(const System& other) = delete;
        System& operator=(System&& other) = delete;
    }; 
}

