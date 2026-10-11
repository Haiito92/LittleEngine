// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <LittleEngine/Core/Platform/Window.hpp>
#include <SDL3/SDL_video.h>

struct Le::WindowImpl
{
    SDL_Window* m_sdlWindow = nullptr;
};

Le::Window::Window(const std::string& title, int width, int height):
m_impl(std::make_unique<WindowImpl>())
{
    m_impl->m_sdlWindow = SDL_CreateWindow(title.c_str(), width, height, 0);
}

Le::Window::Window(Window&& other) noexcept:
m_impl(std::move(other.m_impl))
{
    
}

Le::Window::~Window()
{
    if (m_impl)
    {
        if (m_impl->m_sdlWindow)
        {
            SDL_DestroyWindow(m_impl->m_sdlWindow);
        }
        
        m_impl.reset();
    }
}

Le::Window& Le::Window::operator=(Window&& other) noexcept
{
    m_impl = std::move(other.m_impl);
    
    return *this;
}
