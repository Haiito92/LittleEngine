#include "TypeLibrary.h"

namespace LittleEngine
{
    void TypeLibrary::RegisterType(std::string inTypeName)
    {
        m_types[inTypeName] = Type(inTypeName);
    }

    Type::Type(std::string inName) : Name(inName)
    {
    }
}
