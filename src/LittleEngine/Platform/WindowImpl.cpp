// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <LittleEngine/Platform/WindowImpl.hpp>
#include <SDL3/SDL_video.h>

Le::WindowImpl::WindowImpl(const std::string& title, int width, int height):
m_handle(nullptr)
{
    m_handle = SDL_CreateWindow(title.c_str(), width, height, 0);
}

Le::WindowImpl::~WindowImpl()
{
    if (m_handle)
        SDL_DestroyWindow(m_handle);
}

SDL_Window* Le::WindowImpl::GetHandle()
{
    return m_handle;
}

SDL_Window* Le::WindowImpl::GetHandle() const
{
    return m_handle;
}
