// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#ifdef LE_RENDERING_COMPILE
#define LE_RENDERING_API __declspec(dllexport)
#else
#define LE_RENDERING_API __declspec(dllimport)
#endif
