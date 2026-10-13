// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <LittleEngine/Platform/Export.hpp>

namespace Le
{
    struct Event;

    class LE_PLATFORM_API EventManagerImpl    
    {
    public:
        EventManagerImpl() = default;
        EventManagerImpl(const EventManagerImpl& other) = delete;
        EventManagerImpl(EventManagerImpl&& other) = delete;
        ~EventManagerImpl() = default;

        EventManagerImpl& operator=(const EventManagerImpl& other) = delete;
        EventManagerImpl& operator=(EventManagerImpl&& other) = delete;
        
        bool PollEvent(Event& event) const;
    private:
    };
}

#include <LittleEngine/Platform/EventManagerImpl.inl>
