#include "../Headers/Platform/Game.h"

using namespace plataform;

int main() {

	Game* game = Game::getInstance();

	game->initDisplay();

	game->run();
}
