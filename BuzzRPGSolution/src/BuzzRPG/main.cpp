#include "Game.h"


int main(int argc, char* args[]) {

    BuzzRPG::Game game;

    if (!game.Init()) {
        game.Quit();
        return -1;
    }

    game.Update();

    game.Quit();

    return 0;
}