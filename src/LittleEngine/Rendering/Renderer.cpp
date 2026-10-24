// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <LittleEngine/Rendering/Renderer.hpp>
#include <LittleEngine/Core/Window.hpp>
#include <LittleEngine/Rendering/IRendererImpl.hpp>
#include <fmt/printf.h>

Le::Renderer::Renderer(std::unique_ptr<IRendererImpl> impl):
m_impl(std::move(impl))
{
}

Le::Renderer::~Renderer()
{
    if (m_impl)
        m_impl.reset();
}

void Le::Renderer::RenderLine(float x1, float y1, float x2, float y2)
{
    if (m_impl)
        m_impl->RenderLine(x1, y1, x2, y2);
}

void Le::Renderer::RenderFillRect(float x, float y, float width, float height)
{
    if (m_impl)
        m_impl->RenderFillRect(x, y, width, height);
}

void Le::Renderer::RenderCircle(float cx, float cy, float radius, int segments)
{
    if (m_impl)
        m_impl->RenderCircle(cx, cy, radius, segments);
}

void Le::Renderer::Clear()
{
    if (m_impl)
        m_impl->Clear();
}

void Le::Renderer::Present()
{
    if (m_impl)
        m_impl->Present();
}

void Le::Renderer::SetRenderDrawColor(const uint8_t& r, const uint8_t& g, const uint8_t& b, const uint8_t& a)
{
    if (m_impl)
        m_impl->SetRenderDrawColor(r, g, b, a);
}
