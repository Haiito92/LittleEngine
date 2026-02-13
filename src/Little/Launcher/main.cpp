#include <iostream>
#include <Little/Engine/Core/Application.hpp>
#include <Little/Engine/Core/Window.hpp>
#include <fmt/printf.h>

#include <Windows.h>

int main(int argc, char** argv) {

    try
    {
        LE::Application core;
        LE::Window window("Launcher", 1280, 720);
        LE::Window window2("Launcher 2", 1280, 720);

        LE::U32 msg;
        while (GetMessage(reinterpret_cast<LPMSG>(&msg), nullptr, 0, 0))
        {
            TranslateMessage(reinterpret_cast<LPMSG>(&msg));
            DispatchMessage(reinterpret_cast<LPMSG>(&msg));
        }
    }
    catch (const std::exception& e)
    {
        fmt::print("Caught standard exception: {}\n", e.what());
    }
    catch (...)
    {
        fmt::print("Caught unknow exception.\n");
    }
    
    return EXIT_SUCCESS;
}
