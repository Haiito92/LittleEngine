#pragma once

#ifndef LE_CORE_WINDOWMANAGER_HPP
#define LE_CORE_WINDOWMANAGER_HPP

#include <vector>
#include <Little/Engine/Core/Export.hpp>
#include <Little/Engine/Core/Window.hpp>

#undef CreateWindow

namespace LE {

    class LE_CORE_API WindowManager 
    {
    public:
    
        WindowManager();
        WindowManager(const WindowManager& other) = delete;
        WindowManager(WindowManager&& other) = delete;
        ~WindowManager();
        
        WindowManager& operator=(const WindowManager& other) = delete;
        WindowManager& operator=(WindowManager&& other) = delete;

        Window& CreateWindow(const std::string& title, int width, int height );

        bool GetWindowMessage() const;
        
    private:

        void RegisterWindowClass();

        std::vector<Window> m_windows;
    };

}



#endif // LE_CORE_WINDOWMANAGER_HPP
        