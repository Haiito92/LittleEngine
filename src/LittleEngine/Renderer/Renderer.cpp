// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <LittleEngine/Renderer/Renderer.hpp>
#include <LittleEngine/Core/Window.hpp>
#include <LittleEngine/Platform/RendererImpl.hpp>
#include <fmt/printf.h>

Le::Renderer::Renderer(const Window& window):
m_impl(nullptr)
{
}

Le::Renderer::~Renderer()
{
}

void Le::Renderer::RenderLine(float x1, float y1, float x2, float y2)
{
}

void Le::Renderer::RenderFillRect(float x, float y, float width, float height)
{
    
}

void Le::Renderer::RenderCircle(float cx, float cy, float radius, int segments)
{
    
}

void Le::Renderer::Clear()
{
}

void Le::Renderer::Present()
{
}

void Le::Renderer::SetRenderDrawColor(const uint8_t& r, const uint8_t& g, const uint8_t& b, const uint8_t& a)
{
}
