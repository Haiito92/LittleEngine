// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <LittleEngine/SDLBackend/SDLWindowImpl.hpp>
#include <SDL3/SDL_video.h>

Le::SDLWindowImpl::SDLWindowImpl(const std::string& title, int width, int height):
m_handle(nullptr)
{
    m_handle = SDL_CreateWindow(title.c_str(), width, height, 0);
}

Le::SDLWindowImpl::~SDLWindowImpl()
{
    if (m_handle)
        SDL_DestroyWindow(m_handle);
}

SDL_Window* Le::SDLWindowImpl::GetHandle()
{
    return m_handle;
}

SDL_Window* Le::SDLWindowImpl::GetHandle() const
{
    return m_handle;
}
