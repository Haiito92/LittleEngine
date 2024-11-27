#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "Physics/PhysicsSystem.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

SDL_Window* gWindow;
SDL_Renderer* gRenderer;

bool init();
void close();


int main(int argc, char** argv) {

    //Init app & create window
    if(!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        const std::unique_ptr<LE::PhysicsSystem> physicsSystem = std::make_unique<LE::PhysicsSystem>();
        physicsSystem->Init();

        LE::BodyCreationSettings bodyCreationSettings ={
            {SCREEN_WIDTH/2.f, SCREEN_HEIGHT/2.f},
        };
        
        const std::shared_ptr<LE::BodyComponent> bodyComponent =
            physicsSystem->CreateBody(bodyCreationSettings);

        //Time Variables
        Uint64 lastTime = 0;
        Uint64 currentTime = SDL_GetTicks64();
        double t = 0;
        double fixedDeltaTime = 1.0 / 60.0;
        
        bool quitApp = false;
        //Game Loop
        while (!quitApp)
        {
            //Time
            lastTime = currentTime;
            currentTime = SDL_GetTicks64();
            const float deltaTime = (currentTime - lastTime)/ 1000.f;
            
            SDL_Event e;
            //Handle events on queue
            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT)
                {
                    quitApp = true;
                }
            }

            physicsSystem->Update(fixedDeltaTime);
            
            //Clear screen
            SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00,0x00,0xFF);
            SDL_RenderClear(gRenderer);
            
            //Draw Body
            SDL_Rect rect{
                static_cast<int>(bodyComponent->m_pos.m_x) - SCREEN_WIDTH/6/2,
                static_cast<int>(bodyComponent->m_pos.m_y) - SCREEN_HEIGHT/6/2,
                SCREEN_WIDTH/6,
                SCREEN_HEIGHT/6};
            SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00,0x00,0xFF);
            SDL_RenderFillRect(gRenderer, &rect);
            
            //Update screen
            SDL_RenderPresent(gRenderer);
        }
    }
    
    //Free resources & Close app 
    close();
    
    return 0;
}

bool init()
{
    //Initialization flag
    bool success = true;

    //Init SDL modules
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf(" SDL_VIDEO could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow("My Little Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow == nullptr)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            //Create Renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if(gRenderer == nullptr)
            {
                printf("Renderer could not ve created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00,0x00,0xFF);

                //Initialize Images Formats Loading
                int imgFlags = IMG_INIT_PNG;
                if(!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
            }
        }
    }
    
    return success;
}

void close()
{
    //Destroy app window
    SDL_DestroyRenderer(gRenderer);
    gRenderer = nullptr;
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;

    //Quit sdl modules
    IMG_Quit();
    SDL_Quit();
}