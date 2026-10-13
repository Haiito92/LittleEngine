// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <LittleEngine/Core/Platform/Window.hpp>
#include <SDL3/SDL_video.h>


Le::Window::Window(const std::string& title, int width, int height):
m_handle(nullptr)
{
    m_handle = SDL_CreateWindow(title.c_str(), width, height, 0);
}

Le::Window::Window(Window&& other) noexcept:
m_handle(other.m_handle)
{
    other.m_handle = nullptr;
}

Le::Window::~Window()
{
    if (m_handle)
    {
        SDL_DestroyWindow(m_handle);
    }
}

Le::Window& Le::Window::operator=(Window&& other) noexcept
{
    m_handle = other.m_handle;
    other.m_handle = nullptr;
    
    return *this;
}

SDL_Window* Le::Window::GetHandle()
{
    return m_handle;
}

SDL_Window* Le::Window::GetHandle() const
{
    return m_handle;
}
