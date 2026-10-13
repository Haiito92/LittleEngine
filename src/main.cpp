#include <fmt/printf.h>
#include <LittleEngine/Core/Platform/Platform.hpp>
#include <LittleEngine/Core/Platform/Window.hpp>
#include <LittleEngine/Core/Platform/EventManager.hpp>
#include <LittleEngine/Core/Platform/Event.hpp>
#include <LittleEngine/Renderer/Renderer.hpp>
#include <SDL3/SDL.h>

int main(int argc, char **argv) {
    
    Le::Platform platform{};
    Le::Window window("Little Launcher", 1600, 900);
    Le::EventManager eventManager{};
    
    // Le::Renderer renderer(window);
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window.GetHandle(), nullptr);
    if (!renderer)
    {
        fmt::printf("SDL_CreateRenderer() failed: {}", SDL_GetError());
        return 0;
    }
    
    bool isRunning = true;
    while (isRunning)
    {
        Le::Event event;
        while (eventManager.PollEvent(event))
        {
            switch (event.eventType)
            {
            case Le::EventType::Quit:
                isRunning = false;
                break;
            case Le::EventType::WindowCloseRequested:
                isRunning = false;
                break;
            default:
                break;
            }
        }
        
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        
        SDL_RenderClear(renderer);
        
        SDL_RenderPresent(renderer);
        
        // // Rendering
        // renderer.SetRenderDrawColor(33, 33, 33, 255);
        //
        // renderer.Clear();
        //
        // // Rect
        // renderer.SetRenderDrawColor(233, 0, 0, 255);
        // renderer.RenderFillRect(336, 386, 128, 128);
        //
        // // Line
        // renderer.SetRenderDrawColor(0, 233, 0, 255);
        // renderer.RenderLine(736, 450, 864, 450); 
        //
        // // Circle
        // renderer.SetRenderDrawColor(0, 0, 233, 255);
        // renderer.RenderCircle(1200, 450, 64, 64);
        //
        // renderer.Present();
    }
    
    return 0;
}
