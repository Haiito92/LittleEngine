#pragma once
#include <memory>

#include "../API.h"
#include "../Math/Vec2f.h"

namespace LE
{
    struct LE_Physics_API BodyComponent
    {
    public:
        BodyComponent() = default;
        BodyComponent(Vec2f pos);
        BodyComponent(const BodyComponent& other) = delete;
        BodyComponent(BodyComponent&& other) = delete;
        ~BodyComponent() = default;
        
        BodyComponent& operator=(const BodyComponent& other) = delete;
        BodyComponent& operator=(BodyComponent&& other) = delete;

        inline Vec2f GetPos() const;
        void SetPos(const Vec2f& InVec);
    private:
        Vec2f m_pos;

    }; 
}

