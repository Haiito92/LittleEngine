#pragma once
#include <memory>

#include "Entities/Component.h"
#include "API.h"
#include "Core/Math/Vec2f.h"

namespace LittleEngine
{
    class TypeLibrary;
}

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

        static void RegisterType(std::shared_ptr<TypeLibrary>& inOutTypeLibrary);
        
        Vec2f position = Vec2f::ZERO;
    };
}

