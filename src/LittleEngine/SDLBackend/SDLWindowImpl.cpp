// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <stdexcept>
#include <fmt/format.h>
#include <LittleEngine/SDLBackend/SDLWindowImpl.hpp>
#include <SDL3/SDL_video.h>

Le::SDLWindowImpl::SDLWindowImpl(const std::string& title, int width, int height):
m_handle(nullptr)
{
    m_handle = SDL_CreateWindow(title.c_str(), width, height, 0);
    
    if (m_handle == nullptr)
        throw std::runtime_error(fmt::format("SDL_CreateWindow() failed: {}", SDL_GetError()));
}

Le::SDLWindowImpl::~SDLWindowImpl()
{
    if (m_handle)
        SDL_DestroyWindow(m_handle);
}

Le::WindowHandle Le::SDLWindowImpl::GetHandle() const
{
    return WindowHandle{.handle = m_handle, .windowPlatform = WindowPlatform::SDL};
}

SDL_Window* Le::SDLWindowImpl::GetSDLHandle() const
{
    return m_handle;
}
