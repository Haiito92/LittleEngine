// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <string>
#include <LittleEngine/Platform/Export.hpp>

struct SDL_Window;

namespace Le
{
    class LE_PLATFORM_API WindowImpl    
    {
    friend class RendererImpl;
        
    public:
        WindowImpl() = delete;
        WindowImpl(const std::string& title, int width, int height);
        WindowImpl(const WindowImpl& other) = delete;
        WindowImpl(WindowImpl&& other) = delete;
        ~WindowImpl();

        WindowImpl& operator=(const WindowImpl& other) = delete;
        WindowImpl& operator=(WindowImpl&& other) = delete;
        
        SDL_Window* GetHandle();
    private:
        SDL_Window* GetHandle() const;
        
        SDL_Window* m_handle;
    };
}

#include <LittleEngine/Platform/WindowImpl.inl>
