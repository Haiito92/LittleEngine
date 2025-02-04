#pragma once
#include "API.h"

namespace LittleEngine
{
    struct LE_PHYSICS_API CircleComponent
    {
    public:
        CircleComponent()=default;
        CircleComponent(float inRadius):m_radius(inRadius){}
        CircleComponent(const CircleComponent& other) = delete;
        CircleComponent(CircleComponent&& other) = delete;
        ~CircleComponent() =default;

        CircleComponent& operator=(const CircleComponent& other) = delete;
        CircleComponent& operator=(CircleComponent&& other) = delete;

        float m_radius = 1.0f;
    };
}

