#pragma once
#include "Core/Math/Vec2f.h"

namespace LittleEngine
{
    struct LE_PHYSICS_API BodyCreationSettings
    {
    public:
        BodyCreationSettings() = default;
        BodyCreationSettings(const Vec2f& pos, const Vec2f& velocity = Vec2f::ZERO, const float mass = 1.0f):pos(pos), linearVelocity(velocity), mass(mass){}
        BodyCreationSettings(const BodyCreationSettings& other) = delete;
        BodyCreationSettings(BodyCreationSettings&& other) = delete;
        ~BodyCreationSettings() = default;

        BodyCreationSettings& operator=(const BodyCreationSettings& other) = delete;
        BodyCreationSettings& operator=(BodyCreationSettings&& other) = delete;

        Vec2f pos = Vec2f::ZERO;
        Vec2f linearVelocity = Vec2f::ZERO;
        float mass = 1.0f;
    };
}

