#pragma once

#ifndef LE_CORE_WINDOW_HPP
#define LE_CORE_WINDOW_HPP

#include <Windows.h>
#include <string>
#include <Little/Engine/Core/Export.hpp>


namespace LE {

    class LE_CORE_API Window 
    {
    public:
    
        Window(const std::string& title, int width, int height);
        Window(const Window& other) = delete;
        Window(Window&& other) = delete;
        ~Window();
        
        Window& operator=(const Window& other) = delete;
        Window& operator=(Window&& other) = delete;

        static const std::string& GetWindowClassName();
        static int64_t __stdcall WindowProcStatic(HWND hWnd, uint32_t msg, uint64_t wParam, int64_t lParam);
    private:
        HWND m_hWnd;

        int64_t WindowProc(HWND hWnd, uint32_t msg, uint64_t wParam, int64_t lParam);
        
        const static std::string s_className;
    };

}



#endif // LE_CORE_WINDOW_HPP
        