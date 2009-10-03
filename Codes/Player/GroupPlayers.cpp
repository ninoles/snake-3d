#include "../../Headers/Player/GroupPlayers.h"

using namespace Players;

GroupPlayers::GroupPlayers(){
    _players = new GenericList::ArrayList<Player>;
    _currentPlayerName = "";
}

GroupPlayers::GroupPlayers(GenericList::ArrayList<Player>* __players){
    _players = __players;
    _currentPlayerName = "";
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

int GroupPlayers::getNumberOfPlayers(){
    return _players->getSize();
}

int GroupPlayers::getBestPlayerWins(){
    GenericList::ArrayList<Player>::Iterator it = _players->iterator();

    int bestIndex = 0;

    for(int k = 0; it.hasNext() && k < _players->getSize() - 1; ++k)
        (it.next().getWins() < it.next().getWins() ? bestIndex = k : bestIndex = k+1);

    return bestIndex;
}

int GroupPlayers::getBestPlayerMatches(){
    GenericList::ArrayList<Player>::Iterator it = _players->iterator();

    int bestIndex = 0;

    for(int k = 0; it.hasNext() && k < _players->getSize() - 1; ++k)
        (it.next().getNumberGames() < it.next().getNumberGames() ? bestIndex = k : bestIndex = k+1);

    _currentPlayerName = _players->get(bestIndex).getName();

    return bestIndex;
}

int GroupPlayers::getBestRelationshipScoreByMatch(){
    GenericList::ArrayList<Player>::Iterator it = _players->iterator();

    Player tmpPlayer;
    double oldPercent = 0;
    double bestPercent = 0;
    int bestIndex = 0;

    for(int k = 0; it.hasNext(); k++){
        tmpPlayer = it.next();

        oldPercent = tmpPlayer.getScore() / tmpPlayer.getNumberGames();
        
        if (oldPercent >= bestPercent){
            bestPercent = oldPercent;
            bestIndex = k;
        }
    }

    _currentPlayerName = _players->get(bestIndex).getName();

    return bestIndex;
}

std::string GroupPlayers::getCurrentResearchingPlayerName(){
    return _currentPlayerName;
}

int GroupPlayers::getMatchesByPlayer(Player __player){
    int index = searchPlayer(__player);

    if(index == -1)
        return -1;

    return _players->get(index).getNumberGames();
}

int GroupPlayers::getWinsByPlayer(Player __player){
    int index = searchPlayer(__player);

    if(index == -1)
        return -1;

    return _players->get(index).getWins();
}

int GroupPlayers::getScoreByPlayer(Player __player){
    int index = searchPlayer(__player);

    if(index == -1)
        return -1;

    return _players->get(index).getScore();
}

double GroupPlayers::getRelationshipWinsByMatches(Player __player){
    int index = searchPlayer(__player);

    if(index == -1)
        return -1;

    return _players->get(index).getWins() / _players->get(index).getNumberGames();
}

#include "../GenericList/ArrayList.cpp"


