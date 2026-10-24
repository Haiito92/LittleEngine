// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <string>
#include <LittleEngine/SDLBackend/Export.hpp>
#include <LittleEngine/Core/IWindowImpl.hpp>

struct SDL_Window;

namespace Le
{
    class LE_SDLBACKEND_API SDLWindowImpl : public IWindowImpl 
    {
    friend class SDLRendererImpl;
        
    public:
        SDLWindowImpl() = delete;
        SDLWindowImpl(const std::string& title, int width, int height);
        SDLWindowImpl(const SDLWindowImpl& other) = delete;
        SDLWindowImpl(SDLWindowImpl&& other) = delete;
        ~SDLWindowImpl() override;

        SDLWindowImpl& operator=(const SDLWindowImpl& other) = delete;
        SDLWindowImpl& operator=(SDLWindowImpl&& other) = delete;
        
        WindowHandle GetHandle() const override;
    private:
        SDL_Window* GetSDLHandle() const;
        
        SDL_Window* m_handle;
    };
}

#include <LittleEngine/SDLBackend/SDLWindowImpl.inl>
