#include <iostream>
#include <Little/Engine/Core/Core.hpp>
#include <Little/Engine/Core/Window.hpp>
#include <fmt/printf.h>

int main(int argc, char** argv) {

    try
    {
        LE::Core core;
        LE::Window window("Launcher", 1280, 720);
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
