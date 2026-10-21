// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <string>
#include <LittleEngine/SDLBackend/Export.hpp>

struct SDL_Window;

namespace Le
{
    class LE_SDLBACKEND_API SDLWindowImpl    
    {
    friend class SDLRendererImpl;
        
    public:
        SDLWindowImpl() = delete;
        SDLWindowImpl(const std::string& title, int width, int height);
        SDLWindowImpl(const SDLWindowImpl& other) = delete;
        SDLWindowImpl(SDLWindowImpl&& other) = delete;
        ~SDLWindowImpl();

        SDLWindowImpl& operator=(const SDLWindowImpl& other) = delete;
        SDLWindowImpl& operator=(SDLWindowImpl&& other) = delete;
        
        SDL_Window* GetHandle();
    private:
        SDL_Window* GetHandle() const;
        
        SDL_Window* m_handle;
    };
}

#include <LittleEngine/SDLBackend/SDLWindowImpl.inl>
