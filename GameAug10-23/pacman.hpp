//
//  pacman.hpp
//  GameAug10-23
//
//  Created by Colin Maloney on 8/10/23.
//

#ifndef pacman_hpp
#define pacman_hpp

#include <stdio.h>
#include <SDL2/SDL.h>




class Pacman{
public:
    SDL_Renderer* renderer;
    Pacman();
    void drawMap();
    

};
#endif /* pacman_hpp */
