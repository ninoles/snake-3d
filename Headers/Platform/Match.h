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
            DIF_EASY,
            DIF_MEDIUM,
            DIF_HARD,
            DIF_EXTREME
        };

        private:

            int _maxPoints;
            bool _intelligence;
            int _numberOfPlayers;
            Dificulty _dificulty;

            Players::GroupPlayers *_players;

            file::ConfMatch *_config;

        public:

			Match();

            void setProperties();
    };
}

#endif // MATCH_H_INCLUDED
