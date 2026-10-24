// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <LittleEngine/Core/EventManager.hpp>
#include <LittleEngine/Core/IEventManagerImpl.hpp>

Le::EventManager::EventManager(std::unique_ptr<IEventManagerImpl> impl):
m_impl(std::move(impl))
{
    
}

Le::EventManager::EventManager(EventManager&& other) noexcept:
m_impl(std::move(other.m_impl))
{
}

Le::EventManager::~EventManager()
{
    if (m_impl)
        m_impl.reset();
}

Le::EventManager& Le::EventManager::operator=(EventManager&& other) noexcept
{
    m_impl = std::move(other.m_impl);
    return *this;
}

bool Le::EventManager::PollEvent(Event& event) const
{
    if (m_impl)
        return m_impl->PollEvent(event);
    
    return false;
}
