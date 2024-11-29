#include "BodyComponent.h"
#include "Physics/Collision/ShapeComponents/CircleComponent.h"
namespace LE
{
    BodyComponent::BodyComponent(const BodyCreationSettings& inSettings):m_pos(inSettings.m_pos), m_linearVelocity(inSettings.m_linearVelocity), m_mass(inSettings.m_mass)
    {
        m_circleShape = std::make_unique<CircleComponent>(50.0f);
    }
}

