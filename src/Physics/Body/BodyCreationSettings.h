#pragma once
#include "../../Math/Vec2f.h"

namespace LE
{
    struct BodyCreationSettings
    {
    public:
        BodyCreationSettings() = default;
        BodyCreationSettings(const Vec2f& pos, const Vec2f& velocity = Vec2f::zero):m_pos(pos), m_velocity(velocity){}
        BodyCreationSettings(const BodyCreationSettings& other) = delete;
        BodyCreationSettings(BodyCreationSettings&& other) = delete;
        ~BodyCreationSettings() = default;

        BodyCreationSettings& operator=(const BodyCreationSettings& other) = delete;
        BodyCreationSettings& operator=(BodyCreationSettings&& other) = delete;

        Vec2f m_pos = Vec2f::zero;
        Vec2f m_velocity = Vec2f::zero;
    };
}

