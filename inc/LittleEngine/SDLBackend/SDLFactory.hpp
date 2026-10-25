// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <memory>
#include <string>
#include <LittleEngine/SDLBackend/Export.hpp>

namespace Le
{
    class IWindow;
    class IEventManager;
    class IRenderer;
    
    std::unique_ptr<IWindow> LE_SDLBACKEND_API CreateSDLWindow(const std::string& title, int width, int height);
    std::unique_ptr<IEventManager> LE_SDLBACKEND_API CreateSDLEventManager();
    std::unique_ptr<IRenderer> LE_SDLBACKEND_API CreateSDLRenderer(const IWindow& window);
}

#include <LittleEngine/SDLBackend/SDLFactory.inl>
