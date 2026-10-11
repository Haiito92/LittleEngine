// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)
#include <LittleEngine/Core/Application.hpp>
#include <LittleEngine/Core/Platform/Platform.hpp>
#include <LittleEngine/Core/Platform/Window.hpp>
#include <LittleEngine/Core/Platform/EventManager.hpp>
#include <LittleEngine/Core/Platform/Event.hpp>

void Le::Application::Run()
{
    Platform platform = Platform();
    
    Window window = Window("Little Launcher", 1600, 900);
    EventManager eventManager = EventManager();
    
    bool isRunning = true;
    while (isRunning)
    {
        Event event;
        while (eventManager.PollEvent(event))
        {
            switch (event.eventType)
            {
            case EventType::Quit:
                isRunning = false;
                break;
            case EventType::WindowCloseRequested:
                isRunning = false;
                break;
            default:
                break;
            }
        }
    }
}
