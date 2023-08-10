#include "PacmanGame.hpp"

int main()
{
    Engine* game = new PacmanGame();
    if(!game->init()){
        game->clear();
        delete game;
        return 1;
    }
    game->loop();
    game->clear();
    
    delete game;
}
