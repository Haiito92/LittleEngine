// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <memory>
#include <LittleEngine/Core/Export.hpp>

namespace Le
{
    class EventManagerImpl;
    struct Event;

    class LE_CORE_API EventManager    
    {
    public:
        EventManager();
        EventManager(const EventManager& other) = delete;
        EventManager(EventManager&& other) = delete;
        ~EventManager();

        EventManager& operator=(const EventManager& other) = delete;
        EventManager& operator=(EventManager&& other) = delete;
        
        bool PollEvent(Event& event) const;
    private:
        std::unique_ptr<EventManagerImpl> m_impl;
    };
}

#include <LittleEngine/Core/EventManager.inl>
