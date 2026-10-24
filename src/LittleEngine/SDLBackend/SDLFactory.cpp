// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <LittleEngine/SDLBackend/SDLFactory.hpp>
#include <LittleEngine/SDLBackend/SDLRendererImpl.hpp>
#include <LittleEngine/SDLBackend/SDLWindowImpl.hpp>

#include "LittleEngine/SDLBackend/SDLEventManagerImpl.hpp"

namespace Le
{
    Window CreateSDLWindow(const std::string& title, int width, int height)
    {
        
        return {std::make_unique<SDLWindowImpl>(title.c_str(), width, height)};
    }

    EventManager CreateSDLEventManager()
    {
        return {std::make_unique<SDLEventManagerImpl>()};
    }

    // std::unique_ptr<IRendererImpl> CreateSDLRendererImpl()
    // {
    //     return std::make_unique<SDLRendererImpl>();
    // }
}
