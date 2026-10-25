#include <fmt/printf.h>
#include <LittleEngine/SDLBackend/SDLContext.hpp>
#include <LittleEngine/Core/IWindow.hpp>
#include <LittleEngine/Core/IEventManager.hpp>
#include <LittleEngine/Core/Event.hpp>
#include <LittleEngine/Rendering/IRenderer.hpp>
#include <LittleEngine/SDLBackend/SDLFactory.hpp>

int main(int argc, char **argv) {
    
    Le::SDLContext sdlContext{};
    std::unique_ptr<Le::IWindow> window = Le::CreateSDLWindow("Little Launcher", 1600, 900);
    std::unique_ptr<Le::IEventManager> eventManager = Le::CreateSDLEventManager();
    std::unique_ptr<Le::IRenderer> renderer = Le::CreateSDLRenderer(*window);
    
    bool isRunning = true;
    while (isRunning)
    {
        Le::Event event;
        while (eventManager->PollEvent(event))
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
        
        renderer->SetRenderDrawColor(33, 33, 33, 255);
        renderer->Clear();
        
        // Rect
        renderer->SetRenderDrawColor(233, 0, 0, 255);
        renderer->RenderFillRect(336, 386, 128, 128);
        
        // Line
        renderer->SetRenderDrawColor(0, 233, 0, 255);
        renderer->RenderLine(736, 450, 864, 450); 
        
        // Circle
        renderer->SetRenderDrawColor(0, 0, 233, 255);
        renderer->RenderCircle(1200, 450, 64, 64);
        
        renderer->Present();
    }
    
    return 0;
}
