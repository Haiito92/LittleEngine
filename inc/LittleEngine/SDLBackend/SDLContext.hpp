// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <LittleEngine/SDLBackend/Export.hpp>

namespace Le
{
    class LE_SDLBACKEND_API SDLContext    
    {
    public:
        SDLContext();
        SDLContext(const SDLContext& other) = delete;
        SDLContext(SDLContext&& other) = delete;
        ~SDLContext();

        SDLContext& operator=(const SDLContext& other) = delete;
        SDLContext& operator=(SDLContext&& other) = delete;
    private:
    };
}

#include <LittleEngine/SDLBackend/SDLContext.inl>
