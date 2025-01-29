#pragma once
#include <iostream>
#include <map>
#include <string>

#include "API.h"

namespace LittleEngine
{
    struct Type;

    class LE_CORE_API TypeRegistry
    {
    public:
        TypeRegistry() = default;
        TypeRegistry(const TypeRegistry& other) = delete;
        TypeRegistry(TypeRegistry&& other) = delete;
        ~TypeRegistry() = default;

        TypeRegistry& operator=(const TypeRegistry& other) = delete;
        TypeRegistry& operator=(TypeRegistry&& other) = delete;

        template<typename T>
        static int GetTypeIndex()
        {
            static int typeIndex = nextTypeId++;
            std::cout << typeIndex << std::endl;
            return typeIndex;
        }

    private:
        static int nextTypeId;
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

