#include "GameWindow.h"
#include <iostream>
int main(int argc, char *argv[])
{
    GameWindow *liverGame= new GameWindow();

    liverGame->game_play();

    delete liverGame;
    return 0;
}
