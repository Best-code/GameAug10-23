//
//  displayText.hpp
//  GameAug10-23
//
//  Created by Colin Maloney on 8/11/23.
//

#ifndef displayText_hpp
#define displayText_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <string>

class TextShower
{
public:
    void init(SDL_Renderer& renderer, SDL_Color color, TTF_Font& font, std::string text, int textX, int textY, int textW, int);
    void changeText(std::string);
    void draw();
    void clear();
    ~TextShower();
    
    std::string text;
    TTF_Font* font;
    
    SDL_Renderer* renderer;
    SDL_Texture* tex;
    SDL_Surface* surface;
    SDL_Color color;
    
    int textW; // 500
    int textH; // 100
    
    int textX; // 65
    int textY; // 650
    SDL_Rect dstrect;
};

#endif /* displayText_hpp */
