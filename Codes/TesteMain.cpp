#include <irrlicht/irrlicht.h>

#include "../Headers/Plataform/Game.h"

using namespace plataform;

int main() {

	Game* game = Game::getInstance();

	game->initDisplay();

	game->run();
}
