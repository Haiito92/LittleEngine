#pragma once

#ifndef LE_CORE_WINDOW_HPP
#define LE_CORE_WINDOW_HPP

#include <string>
#include <Little/Engine/Core/Export.hpp>
#include <Little/Engine/Core/CoreTypes.hpp>

namespace LE {

    class Core;
    
    class LE_CORE_API Window 
    {
    friend Core;

    public:
    
        Window(const std::string& title, int width, int height);
        Window(const Window& other) = delete;
        Window(Window&& other) = delete;
        ~Window();
        
        Window& operator=(const Window& other) = delete;
        Window& operator=(Window&& other) = delete;

        static const std::string& GetWindowClassName();
    private:
        void* m_hWnd;

        I64 WindowProc(void* hWnd, U32 msg, U64 wParam, I64 lParam);
        static I64 __stdcall WindowProcStatic(void* hWnd, U32 msg, U64 wParam, I64 lParam);
        
        const static std::string s_className;
    };

}



#endif // LE_CORE_WINDOW_HPP
        