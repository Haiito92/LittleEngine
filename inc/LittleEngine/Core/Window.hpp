// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once
#include <memory>
#include <string>
#include <LittleEngine/Core/Export.hpp>

struct SDL_Window;

namespace Le
{
    class WindowImpl;
    
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

        const WindowImpl* GetImpl() const;
    private:
        std::unique_ptr<WindowImpl> m_impl;
    };
}

#include <LittleEngine/Core/Window.inl>
