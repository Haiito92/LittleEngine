// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <LittleEngine/Core/Export.hpp>

namespace Le
{
    enum class WindowPlatform
    {
        Unknown,
        SDL
    };
    
    struct WindowHandle
    {
        void* handle = nullptr;
        WindowPlatform windowPlatform = WindowPlatform::Unknown;
    };
    
    class LE_CORE_API IWindow    
    {
    public:
        virtual ~IWindow();

        virtual WindowHandle GetHandle() const = 0;
    private:
    };
}

