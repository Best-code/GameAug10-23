//
//  map.cpp
//  GameAug10-23
//
//  Created by Colin Maloney on 8/11/23.
//

#include "map.hpp"

void Map::init(SDL_Renderer& renderer)
{
    this->renderer = &renderer;
}


void Map::draw(){
    for(int y = 0; y < MAP_ROWS; y++)
    {
        for(int x = 0; x < MAP_COLS; x++)
        {
            if(pacmanMap[y][x] == 1)
            {
                SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
            } else{
                SDL_SetRenderDrawColor(this->renderer, 50, 190, 50, SDL_ALPHA_OPAQUE);
            }
            SDL_Rect blip = {x*BLOCK_SIZE, y*BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE};
            SDL_RenderFillRect(this->renderer, &blip);
        }
    }
}
