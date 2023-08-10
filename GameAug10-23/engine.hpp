//
//  engine.cpp
//  GameAug10-23
//
//  Created by Colin Maloney on 8/10/23.
//

#ifndef engine_hpp
#define engine_hpp
#include <SDL2/SDL.h>



class Engine{
public:
    const int FPS = 60;
    const double frameDelay = 1000/FPS;
    
    Uint32 frameStart;
    int frameTime;
    
    Engine();
    virtual ~Engine();
    virtual bool init();
    virtual void loop();
    virtual void render();
    virtual void update();
    virtual void clear();
    virtual void handleEvent(SDL_Event&);
    
    bool running = true;
    
    SDL_Renderer* renderer;
    SDL_Window* window;
    
};
#endif /* engine_hpp */
