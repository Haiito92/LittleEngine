#pragma once

#ifdef LE_RENDERER_COMPILE
    #define LE_RENDERER_API __declspec(dllexport)
#else
    #define LE_RENDERER_API __declspec(dllimport)
#endif