// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <memory>
#include <LittleEngine/SDLBackend/Export.hpp>

namespace Le
{
    class IRendererImpl;
    
    std::unique_ptr<IRendererImpl> LE_SDLBACKEND_API CreateSDLRendererImpl();
}

#include <LittleEngine/SDLBackend/SDLFactory.inl>
