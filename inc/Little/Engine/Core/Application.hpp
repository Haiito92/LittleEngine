#pragma once

#ifndef LE_CORE_CORE_HPP
#define LE_CORE_CORE_HPP

#include <Little/Engine/Core/Export.hpp>
#include <Little/Engine/Core/WindowManager.hpp>


namespace LE {

    class LE_CORE_API Application 
    {
    public:
    
        Application();
        Application(const Application& other) = delete;
        Application(Application&& other) = delete;
        ~Application();
        
        Application& operator=(const Application& other) = delete;
        Application& operator=(Application&& other) = delete;

        int Run();
        
        WindowManager& GetWindowManager();
        const WindowManager& GetWindowManager() const;
        
    private:

        WindowManager m_windowManager;
    };

}



#endif // LE_CORE_CORE_HPP
        