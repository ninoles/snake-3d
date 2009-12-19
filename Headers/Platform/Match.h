/*
 * Match.h
 *
 *  Created on: 18/12/2009
 *      Author: Henrique Jonas
 */

#ifndef MATCH_H_INCLUDED
#define MATCH_H_INCLUDED

#include "../FilesMan/ConfMatch.h"

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
            int _intelligence;
            int _numberOfPlayers;
            Dificulty _dificulty;

        public:

            Match();

            void setProperties();



    };
}


#endif // MATCH_H_INCLUDED
