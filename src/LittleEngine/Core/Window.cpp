// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <LittleEngine/Core/Window.hpp>
#include <LittleEngine/SDL/WindowImpl.hpp>


Le::Window::Window(const std::string& title, int width, int height):
m_impl(std::make_unique<SDLWindowImpl>(title, width, height))
{
}

Le::Window::Window(Window&& other) noexcept:
m_impl(std::move(other.m_impl))
{
}

Le::Window::~Window()
{
    if (m_impl)
        m_impl.reset();
}

Le::Window& Le::Window::operator=(Window&& other) noexcept
{
    m_impl = std::move(other.m_impl);
    
    return *this;
}

const Le::SDLWindowImpl* Le::Window::GetImpl() const
{
    return m_impl.get();
}
