//
//  characters.cpp
//  GameAug10-23
//
//  Created by Colin Maloney on 8/11/23.
//

#include "characters.hpp"
#include "map.hpp"
#include "PacmanGame.hpp"

#include <iostream>

void Character::init(SDL_Renderer& renderer)
{
    this->renderer = &renderer;
    playerX = BLOCK_SIZE * playerSpawn[0];
    playerY = BLOCK_SIZE * playerSpawn[1];
}

void Character::draw(){
    
    SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_Rect player = {playerX, playerY, BLOCK_SIZE, BLOCK_SIZE};
    SDL_RenderFillRect(this->renderer, &player);
    
    makeChange();
}

bool Character::wallCollide(int x,int y, bool turnCheck)
{
    // Basis for collision is the top left corner
    
    // Top left corner
    if(pacmanMap[y/BLOCK_SIZE][x/BLOCK_SIZE] == 0 ||
       // Top Right corner
       pacmanMap[y/BLOCK_SIZE][int(x+BLOCK_SIZE*.999)/BLOCK_SIZE] == 0 ||
       // Bottom Right corner
       pacmanMap[int(y+BLOCK_SIZE*.999)/BLOCK_SIZE][int(x+BLOCK_SIZE*.999)/BLOCK_SIZE] == 0 ||
       // Bottom Left corner
       pacmanMap[int(y+BLOCK_SIZE*.999)/BLOCK_SIZE][x/BLOCK_SIZE] == 0)
    {
        if(!turnCheck)
            moveBackward();
        return true;
    }
    return false;
}

void Character::move(){
    switch (curDirection) {
        case UP:
            playerY -= playerSpeed;
            break;
        case DOWN:
            playerY += playerSpeed;
            break;
        case RIGHT:
            playerX += playerSpeed;
            break;
        case LEFT:
            playerX -= playerSpeed;
            break;
        default:
            break;
    }
    wallCollide(playerX, playerY, false);
}

void Character::moveBackward(){
    switch (curDirection) {
        case UP:
            playerY += playerSpeed;
            break;
        case DOWN:
            playerY -= playerSpeed;
            break;
        case RIGHT:
            playerX -= playerSpeed;
            break;
        case LEFT:
            playerX += playerSpeed;
            break;
        default:
            break;
    }
}

void Character::makeChange(){
    int testX, testY;
    if (nextDirection == RIGHT)
    {
        testX = playerX+BLOCK_SIZE*1.0001;
        testY = playerY;
        
        if(!wallCollide(testX, testY, true))
        {
            curDirection=nextDirection;
        }
    }
    else if (nextDirection == LEFT)
    {
        testX = playerX-BLOCK_SIZE*.0001;
        testY = playerY;
        
        if(!wallCollide(testX, testY, true))
        {
            curDirection=nextDirection;
        }
    }
    else if (nextDirection == UP)
    {
        testX = playerX;
        testY = playerY-BLOCK_SIZE*.0001;
        
        if(!wallCollide(testX, testY, true))
        {
            curDirection=nextDirection;
        }
    }
    else if (nextDirection == DOWN)
    {
        testX = playerX;
        testY = playerY+BLOCK_SIZE*1.0001;
        
        if(!wallCollide(testX, testY, true))
        {
            curDirection=nextDirection;
        }
    }
}

void Character::changeDirection(DIRECTION dir)
{
    nextDirection = dir;
}

void Character::update()
{
    makeChange();
    move();
    score();
}

void Character::score()
{
    scoreValue += 1;
}
