#include <iostream>
#include "Game.h"

int main()
{
    Game* game = new Game;
    game->gameLoop();

    delete game;

    return EXIT_SUCCESS;
}