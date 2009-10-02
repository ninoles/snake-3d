#ifndef GROUPPLAYERS_H_
#define GROUPPLAYERS_H_

#include "ArrayList.h"
#include "Player.h"

namespace Players{
	class GroupPlayers{

            private:

                GenericList::ArrayList<Player> *_players;

            public:

                GroupPlayers();
                GroupPlayers(GenericList::ArrayList<Player> *__players);
                
                GenericList::ArrayList<Player>* getAllPlayers();

                void addPlayer(Player __player);
                
                Player removePlayer(Player __player);
                Player* getPlayers();
                
                int searchPlayer(Player __player);

                int getNumberOfPlayers();
                int getBestPlayerWins();
                int getBestPlayerMatches();
                int getBestRelationshipWinsByMatch();

                std::string getCurrentResearchingPlayerName();

                int getWinsByPlayer(Player __player);
                int getMatchesByPlayer(Player __player);
                int getRelationshipWinsByMatches(Player __player);

	};
};

#endif /*GROUPPLAYERS_H_*/
