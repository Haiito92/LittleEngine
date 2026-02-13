#include <stdexcept>
#include <Little/Engine/Core/Application.hpp>
#include <Windows.h>
#include <fmt/format.h>
#include <Little/Engine/Core/Window.hpp>

namespace LE {

    Application::Application()
    {
        RegisterWindowClass();
    }

    Application::~Application() = default;

    void Application::RegisterWindowClass()
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
         
                 