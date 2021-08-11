#include "Game.h"


int main(int argc, char* args[]) {

    BuzzRPG::Game game;

    game.Init();

    game.Loop();

    game.Quit();

    return 0;
}