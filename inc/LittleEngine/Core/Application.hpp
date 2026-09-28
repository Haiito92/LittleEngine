// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <LittleEngine/Core/Export.hpp>

namespace Le
{
    class LE_CORE_API Application    
    {
    public:
        Application() = default;
        Application(const Application& other) = delete;
        Application(Application&& other) = delete;
        ~Application() = default;

        Application& operator=(const Application& other) = delete;
        Application& operator=(Application&& other) = delete;
    private:
    }
}

#include <LittleEngine/Core/Application.inl>
