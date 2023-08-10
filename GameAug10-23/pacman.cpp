//
//  pacman.cpp
//  GameAug10-23
//
//  Created by Colin Maloney on 8/10/23.
//

#include "pacman.hpp"



void Pacman::drawMap(){
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            SDL_SetRenderDrawColor(renderer, 66,178,0, SDL_ALPHA_OPAQUE);
            SDL_Rect ball = {20,25, 5, 5};
            SDL_RenderFillRect(renderer, &ball);
        }
    }
}
