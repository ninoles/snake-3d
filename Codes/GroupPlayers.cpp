#include "../Headers/GroupPlayers.h"

using namespace Players;


GroupPlayers::GroupPlayers(){
    _players = new GenericList::ArrayList<Player>;
}

GroupPlayers::GroupPlayers(GenericList::ArrayList<Player>* __players){
    _players = __players;
}

GenericList::ArrayList<Player>* GroupPlayers::getAllPlayers(){
    return _players;
}

void GroupPlayers::addPlayer(Player __player){
    _players->add(__player);
}

Player GroupPlayers::removePlayer(Player __player){
    return _players->remove(searchPlayer(__player));
}

Player* GroupPlayers::getPlayers(){
    GenericList::ArrayList<Player>::Iterator it = _players->iterator();
    
    Player* players = new Player[_players->getSize()];

    for(int k = 0; it.hasNext(); k++)
        players[k] = it.next();

    return players;
}

int GroupPlayers::searchPlayer(Player __player){
    GenericList::ArrayList<Player>::Iterator it = _players->iterator();

    int index = -1;

    for(int k = 0; it.hasNext(); k++)
        if(it.next() == __player)
            index = k;

    return index;
}





#include "ArrayList.cpp"


