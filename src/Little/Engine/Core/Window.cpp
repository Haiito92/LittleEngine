#include <stdexcept>
#include <Little/Engine/Core/Window.hpp>
#include <Windows.h>
#include <fmt/format.h>

namespace LE {

    Window::Window(const std::string& title, int width, int height)
    {
        m_hWnd = CreateWindowEx(
            0,
            s_className.c_str(),
            title.c_str(),
            0,
            0, 0,
            width, height,
            nullptr, nullptr, nullptr, this
            );

        if (m_hWnd == nullptr)
            throw std::runtime_error(fmt::format("Failed to create window: {}", GetLastError()));

        ShowWindow(m_hWnd, SW_SHOWNORMAL);
    }

    Window::~Window()
    {
        if (m_hWnd != nullptr)
        {
            DestroyWindow(m_hWnd);
        }
    }

    const std::string& Window::GetWindowClassName()
    {
        return s_className;
    }

    int64_t Window::WindowProcStatic(HWND hWnd, uint32_t msg, uint64_t wParam, int64_t lParam)
    {
        Window* window = nullptr;

        if (msg == WM_CREATE)
        {
            CREATESTRUCT* createStruct = reinterpret_cast<CREATESTRUCT*>(lParam);
            window = static_cast<Window*>(createStruct->lpCreateParams);
            SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG>(window));
        }
        else
        {
            window = reinterpret_cast<Window*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
        }

        if (window)
            return window->WindowProc(hWnd, msg, wParam, lParam);
        
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }

    int64_t Window::WindowProc(HWND hWnd, uint32_t msg, uint64_t wParam, int64_t lParam)
    {
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }

    const std::string Window::s_className = "LittleEngineWindow";
}
         
                 