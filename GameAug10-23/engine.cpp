//
//  engine.hpp
//  GameAug10-23
//
//  Created by Colin Maloney on 8/10/23.
//


#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "engine.hpp"

using namespace std;

Engine::Engine(){
    running = true;
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        running = false;
    }
    
    if(TTF_Init() != 0) {
        std::cout << "TTF_INIT Error: " << TTF_GetError() << std::endl;
        running = false;
    }
    
    font = TTF_OpenFont("/Users/colinmaloney/Downloads/open-sans/OpenSans-Regular.ttf", 100);
    if(font == NULL)
    {
        std::cout << std::endl << "FONT DIDN'T LOAD" << std::endl << TTF_GetError() << std::endl;
        running = false;
    }
}

Engine::~Engine(){
    SDL_Quit();
    TTF_Quit();
}

bool Engine::init(){
    
    window = SDL_CreateWindow("r/gamedev", 100, 100, 630, 750, SDL_WINDOW_SHOWN);
    if(window == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        
        SDL_Quit();
        
        running = false;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr) {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        
        SDL_DestroyWindow(window);
        SDL_Quit();
        running = false;
    }
    return running;
}

void Engine::handleEvent(SDL_Event& event){
        if(event.type == SDL_QUIT) {
            running = false;
    }
}


void Engine::clear(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
}

void Engine::update(){}
void Engine::render(){
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}


void Engine::loop(){
    SDL_Event event;
    
    while(running) {
        frameStart = SDL_GetTicks();
        
        while(SDL_PollEvent(&event)) {
            handleEvent(event);
        }

        render();
        
        update();
        
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay-frameTime);
        }
    }

}

