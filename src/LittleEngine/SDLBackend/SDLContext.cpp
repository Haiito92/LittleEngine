// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <stdexcept>
#include <LittleEngine/SDLBackend/SDLContext.hpp>
#include <SDL3/SDL_init.h>
#include <fmt/format.h>

Le::SDLContext::SDLContext()
{
    if (!SDL_Init(0)) throw std::runtime_error(fmt::format("SLD_Init() failed: {}", SDL_GetError()));
}

Le::SDLContext::~SDLContext()
{
    SDL_Quit();
}
