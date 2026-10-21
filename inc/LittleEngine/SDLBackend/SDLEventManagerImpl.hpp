// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <LittleEngine/SDLBackend/Export.hpp>

namespace Le
{
    struct Event;

    class LE_SDLBACKEND_API SDLEventManagerImpl    
    {
    public:
        SDLEventManagerImpl() = default;
        SDLEventManagerImpl(const SDLEventManagerImpl& other) = delete;
        SDLEventManagerImpl(SDLEventManagerImpl&& other) = delete;
        ~SDLEventManagerImpl() = default;

        SDLEventManagerImpl& operator=(const SDLEventManagerImpl& other) = delete;
        SDLEventManagerImpl& operator=(SDLEventManagerImpl&& other) = delete;
        
        bool PollEvent(Event& event) const;
    private:
    };
}

#include <LittleEngine/SDLBackend/SDLEventManagerImpl.inl>
