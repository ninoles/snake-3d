#ifndef GROUPPLAYERS_H_
#define GROUPPLAYERS_H_

#include "../GenericList/ArrayList.h"
#include "Player.h"

namespace Players{
	class GroupPlayers{

            private:

                GenericList::ArrayList<Player> *_players;
                std::string _currentPlayerName;

            public:

                GroupPlayers();
                GroupPlayers(GenericList::ArrayList<Player> *__players);
                GroupPlayers(int __numberOfPlayers);
                
                GenericList::ArrayList<Player>* getAllPlayers();

                void addPlayer(Player __player);
                
                Player removePlayer(Player __player);
                Player* getPlayers();
                
                int searchPlayer(Player __player);

                int getNumberOfPlayers();
                int getBestPlayerWins();
                int getBestPlayerMatches();
                int getBestRelationshipScoreByMatch();

                std::string getCurrentResearchingPlayerName();

                int getWinsByPlayer(Player __player);
                int getMatchesByPlayer(Player __player);
                int getScoreByPlayer(Player __player);
                double getRelationshipWinsByMatches(Player __player);

                void moveSnakesToForward();

	};
};

#endif /*GROUPPLAYERS_H_*/
