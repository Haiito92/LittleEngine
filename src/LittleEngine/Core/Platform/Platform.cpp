// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <stdexcept>
#include <LittleEngine/Core/Platform/Platform.hpp>
#include <SDL3/SDL_init.h>
#include <fmt/format.h>

Le::Platform::Platform()
{
    if (!SDL_Init(0)) throw std::runtime_error(fmt::format("SLD_Init() failed: {}", SDL_GetError()));
}

Le::Platform::~Platform()
{
    SDL_Quit();
}
