//
//  PacmanGame.hpp
//  GameAug10-23
//
//  Created by Colin Maloney on 8/11/23.
//

#ifndef PacmanGame_hpp
#define PacmanGame_hpp

#include <stdio.h>
#include "engine.hpp"
#include "map.hpp"

enum COLOR {RED, BLUE, GREEN, ORANGE};
enum DIRECTION {UP, LEFT, DOWN, RIGHT};

class PacmanGame : public Engine
{
public:
    virtual bool init() override;
    virtual void render() override;
    virtual void draw();
    virtual void update() override;
    virtual void handleEvent(SDL_Event&) override;
};

#endif /* PacmanGame_hpp */
