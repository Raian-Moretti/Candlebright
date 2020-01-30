#include "System/Game.hpp"

int main()
{
    srand(time(NULL));
    System::Game game;
    game.run();
    return 0;
}
