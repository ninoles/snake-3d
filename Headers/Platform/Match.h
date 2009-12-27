/*
 * Match.h
 *
 *  Created on: 18/12/2009
 *      Author: Henrique Jonas
 */

#ifndef MATCH_H_INCLUDED
#define MATCH_H_INCLUDED

#include <irrlicht.h>

#include "../FilesMan/ConfMatch.h"
#include "../Player/GroupPlayers.h"

namespace platform{

    class Match{

        enum Dificulty{
            DIF_EASY = 1,
            DIF_MEDIUM,
            DIF_HARD,
            DIF_EXTREME
        };

        private:

            int _maxPoints;
            bool _intelligence;
            int _numberOfPlayers;
            int _dificulty;

            Players::GroupPlayers *_players;

            file::ConfMatch *_config;

        public:

			Match();

            void setProperties();

            void randomPoints();
            void randomBonus();
            void randomPositionPlayers();

            void endMatch();
    };
}

#endif // MATCH_H_INCLUDED
