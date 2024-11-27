#pragma once
#ifdef  LE_COMPILE
#define LE_PHYSICS_API __declspec(dllexport)
#define LE_RENDERING_API __declspec(dllexport)
#else
#define LE_Physics_API __declspec(dllimport)
#define LE_Rendering_API __declspec(dllimport)
#endif