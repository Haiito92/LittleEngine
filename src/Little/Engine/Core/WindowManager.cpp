#include "memory"
#include <stdexcept>
#include <Windows.h>
#include <fmt/format.h>
#include <Little/Engine/Core/Window.hpp>
#include <Little/Engine/Core/WindowManager.hpp>


namespace LE {

    WindowManager::WindowManager():
    m_windows()
    {
        RegisterWindowClass();
    };

    WindowManager::~WindowManager() = default;

    Window& WindowManager::CreateWindow(const std::string& title, int width, int height)
    {
        return m_windows.emplace_back(title, width, height);
    }

    bool WindowManager::GetWindowMessage() const
    {
        MSG msg;
        bool result = GetMessage(&msg, nullptr, 0, 0);

        if (result != 0)
            TranslateMessage(&msg);
            DispatchMessage(&msg);

        return result;
    }

    void WindowManager::RegisterWindowClass()
    {
        WNDCLASSEX wc;
        wc.cbSize = sizeof(WNDCLASSEX);
        wc.style = CS_VREDRAW | CS_HREDRAW;
        wc.lpfnWndProc = reinterpret_cast<WNDPROC>(Window::WindowProcStatic);
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = GetModuleHandle(nullptr);
        wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
        wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
        wc.hbrBackground = nullptr;
        wc.lpszMenuName = nullptr;
        wc.lpszClassName = Window::GetWindowClassName().c_str();
        wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);

        ATOM result = RegisterClassEx(&wc);
        if (result == 0)
            throw std::runtime_error(fmt::format("Failed to register class: {}", GetLastError()));
    }
}
         
                 