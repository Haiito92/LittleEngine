#include "BodyComponent.h"

namespace LE
{
    Vec2f BodyComponent::GetPos() const
    {
        return m_pos;
    }

    void BodyComponent::SetPos(const Vec2f& inVec)
    {
        m_pos = inVec;
    }
}

