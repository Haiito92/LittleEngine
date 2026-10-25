// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <stdexcept>
#include <LittleEngine/SDLBackend/SDLFactory.hpp>
#include <LittleEngine/SDLBackend/SDLRenderer.hpp>
#include <LittleEngine/SDLBackend/SDLWindow.hpp>
#include <LittleEngine/SDLBackend/SDLEventManager.hpp>

namespace Le
{
    std::unique_ptr<IWindow> CreateSDLWindow(const std::string& title, int width, int height)
    {
        return std::make_unique<SDLWindow>(title.c_str(), width, height);
    }

    std::unique_ptr<IEventManager> CreateSDLEventManager()
    {
        return std::make_unique<SDLEventManager>();
    }

    std::unique_ptr<IRenderer> CreateSDLRenderer(const IWindow& window)
    {
        switch (window.GetHandle().windowPlatform)
        {
        case WindowPlatform::SDL:
            {
                const SDLWindow& sdlWindowImpl = static_cast<const SDLWindow&>(window);
                return {std::make_unique<SDLRenderer>(sdlWindowImpl)};
            }
        default:
            throw std::runtime_error("Can't create SDL Renderer from a window other than an SDL_Window.");
        }
    }
}
