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
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT,
            width, height,
            nullptr, nullptr,
            GetModuleHandle(nullptr),
            this
            );

        if (m_hWnd == nullptr)
            throw std::runtime_error(fmt::format("Failed to create window: {}", GetLastError()));

        SetWindowLongPtr(static_cast<HWND>(m_hWnd), GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
        
        ShowWindow(static_cast<HWND>(m_hWnd), SW_SHOWNORMAL);
    }

    Window::~Window()
    {
        if (m_hWnd != nullptr)
        {
            DestroyWindow(static_cast<HWND>(m_hWnd));
        }
    }

    const std::string& Window::GetWindowClassName()
    {
        return s_className;
    }

    int64_t Window::WindowProcStatic(void* hWnd, uint32_t msg, uint64_t wParam, int64_t lParam)
    {
        Window* window = nullptr;

        const HWND tempHWnd = static_cast<HWND>(hWnd);
            
        window = reinterpret_cast<Window*>(GetWindowLongPtr(tempHWnd, GWLP_USERDATA));

        if (window)
            return window->WindowProc(hWnd, msg, wParam, lParam);
        
        return DefWindowProc(tempHWnd, msg, wParam, lParam);
    }

    const void* Window::GetHandle() const
    {
        return m_hWnd;
    }

    int64_t Window::WindowProc(void* hWnd, uint32_t msg, uint64_t wParam, int64_t lParam)
    {
        const HWND tempHWnd = static_cast<HWND>(hWnd);

        switch (msg)
        {
            case WM_PAINT:
            {
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(tempHWnd, &ps);

                // All painting occurs here, between BeginPaint and EndPaint.
                FillRect(hdc, &ps.rcPaint, reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1));
                EndPaint(tempHWnd, &ps);

                return 0;
            }
            case WM_DESTROY:
            {
                PostQuitMessage(0);
                return 0;
            }
        }
        
        return DefWindowProc(tempHWnd, msg, wParam, lParam);
    }

    const std::string Window::s_className = "LittleEngineWindow";
}
         
                 