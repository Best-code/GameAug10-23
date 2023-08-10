//
//  PacmanGame.cpp
//  GameAug10-23
//
//  Created by Colin Maloney on 8/11/23.
//

#include "PacmanGame.hpp"
#include <iostream>
#include "characters.hpp"

Map* map = new Map();
Character* player = new Character();
// Ghost* blue = new Ghost(1);
// Ghost* red = new Ghost(1);

bool PacmanGame::init(){
    Engine::init();
    map->init(*renderer);
    player->init(*renderer);
    return running;
}

void PacmanGame::draw(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer,400, 0, 400, 450);
   
    map->draw();
    player->draw();
}

void PacmanGame::render(){
    SDL_RenderSetViewport(renderer, nullptr);
    SDL_RenderClear(renderer);
    
    draw();
    
    SDL_RenderPresent(renderer);
}

void PacmanGame::update(){
    Engine::update();
    player->move();
    player->makeChange();
}

void PacmanGame::handleEvent(SDL_Event& event){
    Engine::handleEvent(event);
    
    if(event.type == SDL_KEYDOWN){
        switch (event.key.keysym.sym){
            case (SDLK_w):
                player->changeDirection(UP);
                break;
            case (SDLK_s):
                player->changeDirection(DOWN);
                break;
            case (SDLK_d):
                player->changeDirection(RIGHT);
                break;
            case (SDLK_a):
                player->changeDirection(LEFT);
                break;
            default:
                break;
        }
    }
}
