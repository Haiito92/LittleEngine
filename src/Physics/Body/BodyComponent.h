#pragma once
#include <memory>

#include "BodyCreationSettings.h"
#include "../../API.h"
#include "../../Math/Vec2f.h"

namespace LE
{
    struct BodyCreationSettings;
    
    struct LE_Physics_API BodyComponent
    {
    public:
        BodyComponent() = default;
        BodyComponent(const BodyCreationSettings& inSettings):m_pos(inSettings.m_pos), m_velocity(inSettings.m_velocity){}
        BodyComponent(const BodyComponent& other) = delete;
        BodyComponent(BodyComponent&& other) = delete;
        ~BodyComponent() = default;
        
        BodyComponent& operator=(const BodyComponent& other) = delete;
        BodyComponent& operator=(BodyComponent&& other) = delete;

        inline Vec2f GetPos() const;
        inline void SetPos(const Vec2f& inVec);
    private:
        Vec2f m_pos = Vec2f::zero;
        Vec2f m_velocity = Vec2f::zero;

    }; 
}

