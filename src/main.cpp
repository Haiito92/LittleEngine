#include <fmt/printf.h>
#include <LittleEngine/SDLBackend/SDLContext.hpp>
#include <LittleEngine/Core/IWindow.hpp>
#include <LittleEngine/Core/IEventManager.hpp>
#include <LittleEngine/Core/Event.hpp>
#include <LittleEngine/Rendering/IRenderer.hpp>
#include <LittleEngine/SDLBackend/SDLFactory.hpp>
#include <LittleEngine/Rendering/Vertex.hpp>

int main(int argc, char **argv) {
    
    Le::SDLContext sdlContext{};
    std::unique_ptr<Le::IWindow> window = Le::CreateSDLWindow("Little Launcher", Le::Vector2i(1600, 900));
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
        
        renderer->SetRenderDrawColor(Le::Colorui8(33, 33, 33, 255));
        renderer->Clear();
        
        // Geometry
        
        std::vector<Le::Vertex> vertices; // x. = 750.0f, .y = 350.0f
        vertices.reserve(4);
        vertices.push_back({.position = Le::Vector2f(750.0f, 350.f), .color = Le::Colorf(1.0f, 1.0f, 1.0f,1.0f), .uv = Le::Vector2f(0.0f, 0.0f)});
        vertices.push_back({.position = Le::Vector2f(850.0f, 350.f), .color = Le::Colorf(1.0f, 1.0f, 1.0f,1.0f), .uv = Le::Vector2f(1.0f, 0.0f)});
        vertices.push_back({.position = Le::Vector2f(750.0f, 450.f), .color = Le::Colorf(1.0f, 1.0f, 1.0f,1.0f), .uv = Le::Vector2f(0.0f, 1.0f)});
        vertices.push_back({.position = Le::Vector2f(850.0f, 450.f), .color = Le::Colorf(1.0f, 1.0f, 1.0f,1.0f), .uv = Le::Vector2f(1.0f, 1.0f)});
        
        std::vector<int> indices = {0, 1, 2, 1, 3, 2};
        
        renderer->RenderGeometry(vertices, indices);
        
        renderer->Present();
    }
    
    return 0;
}
