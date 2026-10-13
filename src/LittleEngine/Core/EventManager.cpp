// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <LittleEngine/Core/EventManager.hpp>
#include <LittleEngine/Platform/EventManagerImpl.hpp>

Le::EventManager::EventManager():
m_impl(std::make_unique<EventManagerImpl>())
{
}

Le::EventManager::~EventManager()
{
    if (m_impl)
        m_impl.reset();
}

bool Le::EventManager::PollEvent(Event& event) const
{
    if (m_impl)
        return m_impl->PollEvent(event);
    
    return false;
}
