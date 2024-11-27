#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL2_gfxPrimitives.h>

#include "Physics/PhysicsSystem.h"
#include "Rendering/RenderSystem.h"

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

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
        //Create and init systems
        const std::shared_ptr<LE::PhysicsSystem> physicsSystem = std::make_unique<LE::PhysicsSystem>();
        physicsSystem->Init();
        std::shared_ptr<LE::RenderSystem> renderSystem = std::make_unique<LE::RenderSystem>(gRenderer, gWindow);
        renderSystem->Init();
        
        //Create bodies for test
        LE::BodyCreationSettings bodyCreationSettings ={
            {SCREEN_WIDTH/3.f, SCREEN_HEIGHT/2.f},
        };
        LE::BodyCreationSettings bodyCreationSettings2 ={
            {2*SCREEN_WIDTH/3.f, SCREEN_HEIGHT/2.f},
        };
        
        physicsSystem->CreateBody(bodyCreationSettings);
        physicsSystem->CreateBody(bodyCreationSettings2);

        //Time Variables
        double time = 0;
        constexpr double fixedDeltaTime = 1.0 / 60.0;
        
        Uint64 newTime = 0;
        Uint64 currentTime = SDL_GetTicks64();
        double accumulator = 0.0;
        
        bool quitApp = false;
        //Game Loop
        while (!quitApp)
        {
            SDL_Event e;
            //Handle events on queue
            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT)
                {
                    quitApp = true;
                }
            }
            
            //Time
            newTime = SDL_GetTicks64();
            const double frameDeltaTime = (newTime - currentTime)/ 1000.f;
            currentTime = newTime;

            //Accumulator use to know how many fixedUpdate we need to make
            accumulator += frameDeltaTime;

            while(accumulator >= fixedDeltaTime)
            {
                //Update Physics system for as many steps as needed
                physicsSystem->Update(fixedDeltaTime);
                accumulator -= fixedDeltaTime;
                time += fixedDeltaTime;
            }
            
            //Render Update : Passing in the body components to draw the bodies for the demo
            //Later should use internal shape components (linked with body components through an object)
            renderSystem->Update(frameDeltaTime, physicsSystem->GetBodyComponents());
            
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