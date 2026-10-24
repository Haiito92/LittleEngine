// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <LittleEngine/Core/Window.hpp>
#include <LittleEngine/Core/IWindowImpl.hpp>

Le::Window::Window(std::unique_ptr<IWindowImpl> windowImpl):
m_impl(std::move(windowImpl))
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

const Le::IWindowImpl* Le::Window::GetImpl() const
{
    return m_impl.get();
}
