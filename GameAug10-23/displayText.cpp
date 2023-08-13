//
//  displayText.cpp
//  GameAug10-23
//
//  Created by Colin Maloney on 8/11/23.
//
#include <iostream>
#include "displayText.hpp"
void TextShower::init(SDL_Renderer& renderer, SDL_Color color, TTF_Font& font, std::string text, int textX, int textY, int textW, int textH){
    this->renderer = &renderer;
    this->font = &font;
    this->color = color;
    this->text = text;
    this->textX = textX;
    this->textY = textY;
    this->textW = textW;
    this->textH = textH;
    
    dstrect = {textX,textY, textW, textH};
    
    
    changeText(text);
    
    std::cout << "Renderer: " << this->renderer << std::endl;
    std::cout << "font: " << this->font << std::endl;
    std::cout << "color: " << &this->color << std::endl;
    std::cout << "text: " << this->text << std::endl;
    std::cout << "surface: " << this->surface << std::endl;
    std::cout << "tex: " << this->tex << std::endl;
    std::cout << "dstrect: " << &this->dstrect << std::endl;
}

void TextShower::changeText(std::string text)
{
    clear();
    surface = TTF_RenderText_Solid(this->font, text.c_str(), color);
    tex = SDL_CreateTextureFromSurface(this->renderer, surface);
}

void TextShower::draw(){    
    SDL_RenderCopy(renderer, tex, NULL, &dstrect);
}

void TextShower::clear(){
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(tex);
}

TextShower::~TextShower()
{
    clear();
}

