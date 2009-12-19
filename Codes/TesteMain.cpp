#include "../Headers/Base/Frame.h"
#include "../Headers/FilesMan/ConfScore.h"
#include "../Headers/FilesMan/ConfFrame.h"
#include "../Headers/Platform/GUIManagement.h"
#include "../Headers/Platform/Game.h"
#include "../Headers/Player/GroupPlayers.h"

#include <iostream>

using namespace base;
using namespace file;
using namespace platform;
using namespace std;

int main() {

    Game *game = Game::getInstance();

    game->initDisplay();
    game->run();


}
