#pragma once
#include <memory>

#include "BodyCreationSettings.h"
#include "API.h"
#include "Math/Vec2f.h"

namespace LE
{
    struct BodyCreationSettings;
    
    struct LE_Physics_API BodyComponent
    {
    public:
        BodyComponent() = default;
        BodyComponent(const BodyCreationSettings& inSettings):m_pos(inSettings.m_pos), m_linearVelocity(inSettings.m_linearVelocity){}
        BodyComponent(const BodyComponent& other) = delete;
        BodyComponent(BodyComponent&& other) = delete;
        ~BodyComponent() = default;
        
        BodyComponent& operator=(const BodyComponent& other) = delete;
        BodyComponent& operator=(BodyComponent&& other) = delete;

        
        Vec2f m_pos = Vec2f::zero;
        Vec2f m_linearVelocity = Vec2f::zero;
        Vec2f m_force = Vec2f::zero;
        

    }; 
}
