// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <stdexcept>
#include <LittleEngine/SDLBackend/SDLFactory.hpp>
#include <LittleEngine/SDLBackend/SDLRendererImpl.hpp>
#include <LittleEngine/SDLBackend/SDLWindowImpl.hpp>
#include <LittleEngine/Rendering/Renderer.hpp>
#include <LittleEngine/SDLBackend/SDLEventManagerImpl.hpp>

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

    Renderer CreateSDLRenderer(const Window& window)
    {
        const IWindowImpl* windowImpl = window.GetImpl();
        switch (windowImpl->GetHandle().windowPlatform)
        {
        case WindowPlatform::SDL:
            {
                const SDLWindowImpl* sdlWindowImpl = static_cast<const SDLWindowImpl*>(windowImpl);
                return {std::make_unique<SDLRendererImpl>(*sdlWindowImpl)};
            }
        default:
            throw std::runtime_error("Can't create SDL Renderer from a window other than an SDL_Window.");
        }
    }
}
