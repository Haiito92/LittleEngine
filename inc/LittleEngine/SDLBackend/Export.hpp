// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#ifdef LE_SDLBACKEND_COMPILE
#define LE_SDLBACKEND_API __declspec(dllexport)
#else
#define LE_SDLBACKEND_API __declspec(dllimport)
#endif
