// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <LittleEngine/Core/Export.hpp>

namespace Le
{
    struct Event;

    class LE_CORE_API EventManager    
    {
    public:
        EventManager() = default;
        EventManager(const EventManager& other) = delete;
        EventManager(EventManager&& other) = delete;
        ~EventManager() = default;

        EventManager& operator=(const EventManager& other) = delete;
        EventManager& operator=(EventManager&& other) = delete;
        
        bool PollEvent(Event& event) const;
    private:
    };
}

#include <LittleEngine/Core/Platform/EventManager.inl>
