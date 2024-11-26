#include "BodyComponent.h"

namespace LE
{
    BodyComponent::BodyComponent(Vec2f pos):
    m_pos(pos)
    {
        
    }

    Vec2f BodyComponent::GetPos() const
    {
        return m_pos;
    }

    void BodyComponent::SetPos(const Vec2f& InVec)
    {
        m_pos = InVec;
    }
}

