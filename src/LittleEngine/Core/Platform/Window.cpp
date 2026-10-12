// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <LittleEngine/Core/Platform/Window.hpp>
#include <SDL3/SDL_video.h>


Le::Window::Window(const std::string& title, int width, int height):
m_handle(nullptr)
{
    m_handle = SDL_CreateWindow(title.c_str(), width, height, 0);
}

Le::Window::~Window()
{
    if (m_handle)
    {
        SDL_DestroyWindow(m_handle);
    }
}
