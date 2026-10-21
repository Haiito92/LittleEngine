// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <LittleEngine/SDLBackend/SDLFactory.hpp>
#include <LittleEngine/SDLBackend/SDLRendererImpl.hpp>

namespace Le
{
    std::unique_ptr<IRendererImpl> CreateSDLRendererImpl()
    {
        return std::make_unique<SDLRendererImpl>();
    }
}
