#pragma once
#include <memory>

#include "BodyCreationSettings.h"
#include "API.h"
#include "Core/Math/Vec2f.h"
#include "Physics/Collision/ShapeComponents/CircleComponent.h"


namespace LittleEngine
{
    struct BodyCreationSettings;

    struct LE_PHYSICS_API BodyComponent
    {
    public:
        BodyComponent() = default;
        BodyComponent(const BodyCreationSettings& inSettings);
        BodyComponent(const BodyComponent& other) = delete;
        BodyComponent(BodyComponent&& other) = delete;
        ~BodyComponent() = default;
        
        BodyComponent& operator=(const BodyComponent& other) = delete;
        BodyComponent& operator=(BodyComponent&& other) = delete;


        std::unique_ptr<CircleComponent> circleShape = nullptr;
        Vec2f pos = Vec2f::ZERO;
        Vec2f linearVelocity = Vec2f::ZERO;
        Vec2f force = Vec2f::ZERO;
        float mass = 1.0f;
        

    }; 
}

