//
//  map.hpp
//  GameAug10-23
//
//  Created by Colin Maloney on 8/11/23.
//

#ifndef map_hpp
#define map_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

const int MAP_ROWS = 21;
const int MAP_COLS = 21;

const int playerSpawn[] = {10,11}; // Middle

const int ghostSpawners[5][2] = {
    {1,1}, // Top Left
    {19,1}, // Top Right
    {1,19}, // Bottom Left
    {19,19}, // Bottom Right
};

const int BLOCK_SIZE = 30;
                
const int pacmanMap[MAP_ROWS][MAP_COLS] = {
    {0, 0, 0, 0, 0,     0, 0, 0, 0, 0,     0,    0, 0, 0, 0, 0,      0, 0, 0, 0,0},
    {0, 1, 1, 1, 1,     1, 1, 1, 1, 1,     0,    1, 1, 1, 1, 1,      1, 1, 1, 1,0},
    {0, 1, 0, 0, 1,     0, 0, 0, 0, 1,     0,    1, 0, 0, 0, 0,      1, 0, 0, 1,0},
    {0, 1, 0, 0, 1,     0, 0, 0, 0, 1,     0,    1, 0, 0, 0, 0,      1, 0, 0, 1,0},
    {0, 1, 1, 1, 1,     1, 1, 1, 1, 1,     1,    1, 1, 1, 1, 1,      1, 1, 1, 1,0},
    {0, 1, 0, 0, 1,     0, 1, 0, 0, 0,     0,    0, 0, 0, 1, 0,      1, 0, 0, 1,0},
    {0, 1, 1, 1, 1,     0, 1, 1, 1, 1,     0,    1, 1, 1, 1, 0,      1, 1, 1, 1,0},
    

    {0, 0, 0, 0, 1,     0, 0, 0, 0, 1,     0,    1, 0, 0, 0, 0,      1, 0, 0, 0,0},
    {0, 0, 0, 0, 1,     0, 1, 1, 1, 1,     1,    1, 1, 1, 1, 0,      1, 0, 0, 0,0},
    {0, 0, 0, 0, 1,     0, 1, 0, 0, 0,     0,    0, 0, 0, 1, 0,      1, 0, 0, 0,0},
    {0, 0, 0, 0, 1,     0, 1, 0, 0, 0,     0,    0, 0, 0, 1, 0,      1, 0, 0, 0,0},
    {0, 0, 0, 0, 1,     0, 1, 1, 0, 1,     1,    1, 0, 1, 1, 0,      1, 0, 0, 0,0},
    {0, 1, 1, 0, 1,     0, 0, 1, 1, 1,     0,    1, 1, 1, 0, 0,      1, 0, 0, 0,0},



    {0, 1, 1, 1, 1,     1, 1, 1, 0, 1,     0,    1, 0, 1, 1, 1,      1, 1, 1, 1,0},
    {0, 1, 0, 0, 1,     0, 0, 0, 0, 0,     0,    0, 0, 0, 0, 0,      1, 0, 0, 1,0},
    {0, 1, 1, 0, 1,     1, 1, 0, 0, 0,     0,    0, 0, 0, 1, 1,      1, 0, 1, 1,0},
    {0, 0, 1, 0, 1,     0, 1, 1, 1, 1,     0,    1, 1, 1, 1, 0,      1, 0, 1, 0,0},
    {0, 1, 1, 1, 1,     0, 0, 0, 0, 1,     0,    1, 0, 0, 0, 0,      1, 1, 1, 1,0},
    {0, 1, 0, 0, 0,     0, 1, 0, 0, 1,     0,    1, 0, 0, 1, 0,      0, 0, 0, 1,0},
    {0, 1, 1, 1, 1,     1, 1, 1, 1, 1,     1,    1, 1, 1, 1, 1,      1, 1, 1, 1,0},
    {0, 0, 0, 0, 0,     0, 0, 0, 0, 0,     0,    0, 0, 0, 0, 0,      0, 0, 0, 0,0}
};



class Map{
public:
    void init(SDL_Renderer&);
    void draw();
    
    SDL_Renderer* renderer;
};
#endif /* map_hpp */
        
