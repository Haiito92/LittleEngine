// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <string>
#include <LittleEngine/SDLBackend/Export.hpp>
#include <LittleEngine/Core/IWindow.hpp>

struct SDL_Window;

namespace Le
{
    class LE_SDLBACKEND_API SDLWindow : public IWindow 
    {
    friend class SDLRenderer;
        
    public:
        SDLWindow() = delete;
        SDLWindow(const std::string& title, int width, int height);
        SDLWindow(const SDLWindow& other) = delete;
        SDLWindow(SDLWindow&& other) = delete;
        ~SDLWindow() override;

        SDLWindow& operator=(const SDLWindow& other) = delete;
        SDLWindow& operator=(SDLWindow&& other) = delete;
        
        WindowHandle GetHandle() const override;
    private:
        SDL_Window* GetSDLHandle() const;
        
        SDL_Window* m_handle;
    };
}

#include <LittleEngine/SDLBackend/SDLWindow.inl>
