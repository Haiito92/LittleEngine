// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <LittleEngine/SDLBackend/Export.hpp>

#include "LittleEngine/Core/IEventManagerImpl.hpp"

namespace Le
{
    struct Event;

    class LE_SDLBACKEND_API SDLEventManagerImpl : public IEventManagerImpl  
    {
    public:
        SDLEventManagerImpl() = default;
        SDLEventManagerImpl(const SDLEventManagerImpl& other) = delete;
        SDLEventManagerImpl(SDLEventManagerImpl&& other) = delete;
        ~SDLEventManagerImpl() override = default;

        SDLEventManagerImpl& operator=(const SDLEventManagerImpl& other) = delete;
        SDLEventManagerImpl& operator=(SDLEventManagerImpl&& other) = delete;
        
        bool PollEvent(Event& event) const override;
    private:
    };
}

#include <LittleEngine/SDLBackend/SDLEventManagerImpl.inl>
