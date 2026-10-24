// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <memory>
#include <LittleEngine/Core/Export.hpp>

namespace Le
{
    class IEventManagerImpl;
    struct Event;

    class LE_CORE_API EventManager    
    {
    public:
        EventManager() = delete;
        EventManager(std::unique_ptr<IEventManagerImpl> impl);
        EventManager(const EventManager& other) = delete;
        EventManager(EventManager&& other) noexcept;
        ~EventManager();
    
        EventManager& operator=(const EventManager& other) = delete;
        EventManager& operator=(EventManager&& other) noexcept;
        
        bool PollEvent(Event& event) const;
    private:
        std::unique_ptr<IEventManagerImpl> m_impl;
    };
}

#include <LittleEngine/Core/EventManager.inl>
