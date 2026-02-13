#include <Little/Engine/Core/Application.hpp>

namespace LE {

    Application::Application():
    m_windowManager()
    {
    }

    Application::~Application() = default;

    int Application::Run()
    {
        while (m_windowManager.GetWindowMessage())
        {
            
        }
        
        return EXIT_SUCCESS;
    }

    WindowManager& Application::GetWindowManager()
    {
        return m_windowManager;
    }

    const WindowManager& Application::GetWindowManager() const
    {
        return m_windowManager;
    }
}
         
                 