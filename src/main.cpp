#include <fmt/printf.h>
#include <LittleEngine/Platform/Platform.hpp>
#include <LittleEngine/Core/Window.hpp>
#include <LittleEngine/Core/EventManager.hpp>
#include <LittleEngine/Renderer/Renderer.hpp>
#include <LittleEngine/Platform/RendererImpl.hpp>
#include "LittleEngine/Platform/Event.hpp"

int main(int argc, char **argv) {
    
    Le::Platform platform{};
    Le::Window window("Little Launcher", 1600, 900);
    Le::EventManager eventManager{};
    
    Le::RendererImpl renderer(*window.GetImpl());
    
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
        
        // Rendering
        renderer.SetRenderDrawColor(33, 33, 33, 255);
        
        renderer.Clear();
        
        // Rect
        renderer.SetRenderDrawColor(233, 0, 0, 255);
        renderer.RenderFillRect(336, 386, 128, 128);
        
        // Line
        renderer.SetRenderDrawColor(0, 233, 0, 255);
        renderer.RenderLine(736, 450, 864, 450); 
        
        // Circle
        renderer.SetRenderDrawColor(0, 0, 233, 255);
        renderer.RenderCircle(1200, 450, 64, 64);
        
        renderer.Present();
    }
    
    return 0;
}
