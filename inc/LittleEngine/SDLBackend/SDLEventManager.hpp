// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <LittleEngine/SDLBackend/Export.hpp>

#include "LittleEngine/Core/IEventManager.hpp"

namespace Le
{
    struct Event;

    class LE_SDLBACKEND_API SDLEventManager : public IEventManager  
    {
    public:
        SDLEventManager() = default;
        SDLEventManager(const SDLEventManager& other) = delete;
        SDLEventManager(SDLEventManager&& other) = delete;
        ~SDLEventManager() override = default;

        SDLEventManager& operator=(const SDLEventManager& other) = delete;
        SDLEventManager& operator=(SDLEventManager&& other) = delete;
        
        bool PollEvent(Event& event) const override;
    private:
    };
}

#include <LittleEngine/SDLBackend/SDLEventManager.inl>
