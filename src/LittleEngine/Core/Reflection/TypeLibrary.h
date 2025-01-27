#pragma once
#include <map>
#include <string>

#include "API.h"

namespace LittleEngine
{
    struct Type;

    class LE_CORE_API TypeLibrary
    {
    public:
        TypeLibrary() = default;
        TypeLibrary(const TypeLibrary& other) = delete;
        TypeLibrary(TypeLibrary&& other) = delete;
        ~TypeLibrary() = default;

        TypeLibrary& operator=(const TypeLibrary& other) = delete;
        TypeLibrary& operator=(TypeLibrary&& other) = delete;
        
        void RegisterType(std::string inTypeName);
        
    private:
        std::map<std::string, Type> m_types;

    
    };

    struct Type
    {
    public:
        Type() = delete;
        Type(std::string inName);
        Type(const Type& other) = delete;
        Type(Type&& other) = delete;
        ~Type() = default;

        Type& operator=(const Type& other) = default;
        Type& operator=(Type&& other) = default;
        
        std::string Name;
    };
}

