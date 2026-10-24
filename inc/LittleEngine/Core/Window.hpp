// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once
#include <memory>
#include <LittleEngine/Core/Export.hpp>

namespace Le
{
    class IWindowImpl;
    class SDLWindowImpl;
    
    class LE_CORE_API Window    
    {
    friend class Renderer;
        
    public:
        Window() = delete;
        Window(std::unique_ptr<IWindowImpl> windowImpl);
        Window(const Window& other) = delete;
        Window(Window&& other) noexcept;
        ~Window();

        Window& operator=(const Window& other) = delete;
        Window& operator=(Window&& other) noexcept;

    private:
        const IWindowImpl* GetImpl() const;
        
        std::unique_ptr<IWindowImpl> m_impl;
    };
}

#include <LittleEngine/Core/Window.inl>
