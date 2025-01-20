#include "BodyComponent.h"
#include "Physics/Collision/ShapeComponents/CircleComponent.h"
namespace LittleEngine
{
    BodyComponent::BodyComponent(const BodyCreationSettings& inSettings):pos(inSettings.pos), linearVelocity(inSettings.linearVelocity), mass(inSettings.mass)
    {
        circleShape = std::make_unique<CircleComponent>(50.0f);
    }
}

