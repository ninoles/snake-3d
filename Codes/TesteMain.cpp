#include "../Headers/Platform/Game.h"

using namespace platform;

int main() {

    Game *game = Game::getInstance();

    game->initDisplay();
    game->run();


}
