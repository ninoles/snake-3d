#include "../Headers/GroupPlayers.h"

using namespace Players;


GroupPlayers::GroupPlayers(){
}

GroupPlayers::GroupPlayers(GenericList::ArrayList<Player> __players){
    _players = __players;
}


