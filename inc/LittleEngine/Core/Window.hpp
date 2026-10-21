// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once
#include <memory>
#include <string>
#include <LittleEngine/Core/Export.hpp>

namespace Le
{
    class SDLWindowImpl;
    
    class LE_CORE_API Window    
    {
    friend class Renderer;
        
    public:
        Window() = delete;
        Window(const std::string& title, int width, int height);
        Window(const Window& other) = delete;
        Window(Window&& other) noexcept;
        ~Window();

        Window& operator=(const Window& other) = delete;
        Window& operator=(Window&& other) noexcept;

    private:
        const SDLWindowImpl* GetImpl() const;
        
        std::unique_ptr<SDLWindowImpl> m_impl;
    };
}

#include <LittleEngine/Core/Window.inl>
