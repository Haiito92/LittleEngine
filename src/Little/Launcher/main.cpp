#include <iostream>
#include <fmt/printf.h>
#include <Little/Engine/Core/Application.hpp>
#include <Little/Engine/Core/Window.hpp>

int main(int argc, char** argv) {

    try
    {
        LE::Application app;
        LE::WindowManager& windowManager = app.GetWindowManager();
        LE::Window& window = windowManager.CreateWindow("Launcher", 1280, 720);

        return app.Run();
    }
    catch (const std::exception& e)
    {
        fmt::print("Caught standard exception: {}\n", e.what());
    }
    catch (...)
    {
        fmt::print("Caught unknow exception.\n");
    }
    
    return EXIT_FAILURE;
}
