/*
 * Match.h
 *
 *  Created on: 18/12/2009
 *      Author: Henrique Jonas
 */

#ifndef MATCH_H_INCLUDED
#define MATCH_H_INCLUDED

#include <irrlicht.h>
#include <time.h>

#include "../FilesMan/ConfMatch.h"
#include "../Player/GroupPlayers.h"
#include "Map.h"
#include "Point.h"

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
            platform::Map *_map;
            platform::Point *_points;
            base::FrameAnimatedNode *_bonus;
            file::ConfMatch *_config;

            void setProperties();

            void randomPoints();
            void randomBonus();
            irr::core::vector3df randomPositionPlayers();

            bool endMatch();

        public:

			Match();

			void initMatch(irr::video::IVideoDriver *__driver, irr::scene::ISceneManager *__sceneManager, NewtonWorld *__newtonW);
            void runMatch();

            Players::GroupPlayers* getGroupPlayers();
            platform::Map* getMap();
    };
}

#endif // MATCH_H_INCLUDED
