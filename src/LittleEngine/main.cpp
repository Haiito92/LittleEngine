#include <iostream>
#include <memory>
#include <memory>
#include <SDL.h>
#include <SDL_image.h>

#include "Core/Reflection/TypeLibrary.h"
#include "Entities/EntityManager.h"
#include "Entities/EntityWorld.h"
#include "Entities/Components/TransformComponent.h"
#include "Physics/PhysicsSystem.h"
#include "Rendering/RenderSystem.h"


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
        //We create a TypeLibrary to be able to do Reflection on classes
        std::shared_ptr<LittleEngine::TypeLibrary> typeLibrary = std::make_shared<LittleEngine::TypeLibrary>();
        LittleEngine::TransformComponent::RegisterType(typeLibrary);
        
        //We create the EntityWorld first since he contains de EntityManager and the Systems
        std::shared_ptr<LittleEngine::EntityWorld> entityWorld = std::make_shared<LittleEngine::EntityWorld>();

        //Something old lol
                    // Create and init systems
                    //  const std::shared_ptr<LittleEngine::PhysicsSystem> physicsSystem = std::make_shared<LittleEngine::PhysicsSystem>(entityManager);
                    //  physicsSystem->Init();
                    //  std::shared_ptr<LittleEngine::RenderSystem> renderSystem = std::make_shared<LittleEngine::RenderSystem>(gRenderer, gWindow);
                    //  renderSystem->Init();
                    //
                    // Create bodies for test
                    //  LittleEngine::BodyCreationSettings bodyCreationSettings ={
                    //      {SCREEN_WIDTH/2.f, SCREEN_HEIGHT/3.f},
                    //      {300.0f, 0.0f}
                    //  };
                    //  LE::BodyCreationSettings bodyCreationSettings2 ={
                    //      {SCREEN_WIDTH/2.f, 2*SCREEN_HEIGHT/3.f},
                    //  };
                    //
                    //  physicsSystem->CreateBody(bodyCreationSettings);
                    //  physicsSystem->CreateBody(bodyCreationSettings2);

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
                // physicsSystem->Update(fixedDeltaTime, gWindow);
                entityWorld->WorldFixedUpdate(fixedDeltaTime);
                accumulator -= fixedDeltaTime;
                time += fixedDeltaTime;
            }

            //Update
            entityWorld->WorldUpdate(frameDeltaTime);
            
            //Render Update : Passing in the body components to draw the bodies for the demo
            //Later should use internal shape components (linked with body components through an object)
            // renderSystem->Update(frameDeltaTime, physicsSystem->GetBodyComponents());
            entityWorld->WorldRenderUpdate();
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