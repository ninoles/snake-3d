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
#include <iostream>

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

            irr::core::vector3df randomPositionPlayers();

            bool endMatch();

        public:

			Match();

			void initMatch(irr::video::IVideoDriver *__driver, irr::scene::ISceneManager *__sceneManager, NewtonWorld *__newtonW);
            bool runMatch();

            void randomPoints();
            void randomBonus();

            void setVisiblePoint(bool __visible);
            bool isVisiblePoint();

            Players::GroupPlayers* getGroupPlayers();
            platform::Map* getMap();
            platform::Point* getPoint();
    };
}

#endif // MATCH_H_INCLUDED
