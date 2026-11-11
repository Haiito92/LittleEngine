// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#ifdef LE_MATH_COMPILE
#define LE_MATH_API __declspec(dllexport)
#else
#define LE_MATH_API __declspec(dllimport)
#endif
