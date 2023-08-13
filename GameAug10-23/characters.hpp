//
//  characters.cpp
//  GameAug10-23
//
//  Created by Colin Maloney on 8/11/23.
//

#ifndef characters_hpp
#define characters_hpp

#include "characters.hpp"
#include <SDL2/SDL.h>
#include "PacmanGame.hpp"
#include "map.hpp"

const int playerSpeed = 1;

class Character{
public:
    virtual void init(SDL_Renderer&);
    virtual void update();
    void score();
    virtual void draw();
    virtual void move();
    virtual void moveBackward();
    virtual void changeDirection(DIRECTION);
    virtual bool wallCollide(int, int, bool);
    virtual void makeChange();
    
    SDL_Renderer* renderer;
    
    int playerX, playerY;
    
    int scoreValue = 0;
    
    DIRECTION curDirection = UP;
    DIRECTION nextDirection = UP;
    DIRECTION tempDirection = UP;
    
    bool canTurn = false;
    bool madeTurn = false;
};

#endif /* characters_hpp */
