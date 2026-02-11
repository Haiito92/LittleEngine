#pragma once

#ifndef LE_CORE_WINDOW_HPP
#define LE_CORE_WINDOW_HPP

#include <string>
#include <Little/Engine/Core/Export.hpp>

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

        int64_t WindowProc(void* hWnd, uint32_t msg, uint64_t wParam, int64_t lParam);
        static int64_t __stdcall WindowProcStatic(void* hWnd, uint32_t msg, uint64_t wParam, int64_t lParam);
        
        const static std::string s_className;
    };

}



#endif // LE_CORE_WINDOW_HPP
        