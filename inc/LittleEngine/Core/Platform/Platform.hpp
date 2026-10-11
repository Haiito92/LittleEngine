// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <LittleEngine/Core/Export.hpp>

namespace Le
{
    class LE_CORE_API Platform    
    {
    public:
        Platform();
        Platform(const Platform& other) = delete;
        Platform(Platform&& other) = delete;
        ~Platform();

        Platform& operator=(const Platform& other) = delete;
        Platform& operator=(Platform&& other) = delete;
    private:
    };
}

#include <LittleEngine/Core/Platform/Platform.inl>
