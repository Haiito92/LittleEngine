#pragma once
#include "Entities/Component.h"
#include "API.h"
#include "Core/Math/Vec2f.h"

namespace LittleEngine
{
    struct LE_ENTITIES_API TransformComponent : public Component
    {
    public:
        TransformComponent() = default;
        TransformComponent(const TransformComponent& other) = delete;
        TransformComponent(TransformComponent&& other) = delete;
        ~TransformComponent() = default;

        TransformComponent& operator=(const TransformComponent& other) = delete;
        TransformComponent& operator=(TransformComponent&& other) = delete;
        
        Vec2f position = Vec2f::ZERO;
    };
}

