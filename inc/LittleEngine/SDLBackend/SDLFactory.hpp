// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <string>
#include <LittleEngine/SDLBackend/Export.hpp>
#include <LittleEngine/Core/Window.hpp>
#include <LittleEngine/Core/EventManager.hpp>

namespace Le
{
    class IRendererImpl;
    
    Window LE_SDLBACKEND_API CreateSDLWindow(const std::string& title, int width, int height);
    EventManager LE_SDLBACKEND_API CreateSDLEventManager();
    // std::unique_ptr<IRendererImpl> LE_SDLBACKEND_API CreateSDLRendererImpl(const IWindowImpl& WindowImpl);
}

#include <LittleEngine/SDLBackend/SDLFactory.inl>
