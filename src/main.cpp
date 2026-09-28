#include <iostream>
#include <SDL3/SDL.h>

int main(int argc, char **argv) {
    
    SDL_Init(0);    
    
    SDL_Window* window = SDL_CreateWindow("LittleLauncher", 1600, 900, 0);
    
    bool isRunning = true;
    while (isRunning)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
                isRunning = false;
                break;
            case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
                isRunning = false;
                break;
            default:
                break;
            }
        }
    }
    
    return 0;
}
