#ifndef CPLAYERHUMAN_H
#define CPLAYERHUMAN_H

#include "cPlayer.h"

/** Human Player */
class cPlayerHuman : public cPlayer
{
    public:
        cPlayerHuman();

        /** Place a piece
            @param[in] point where piece to be placed
        */
        void Places( int point );

        /** Remove one of the computer's pieces
            @param[in] point where the piece to be removed is placed
        */
        void Remove( int point );

        /** Start moving a piece
            @param[in] point where piece to be moved is currently placed
        */
        void Move1( int point );

        /** complete move
            @param[in] point of destination
        */
        void Move2( int point  );

};

extern cPlayerHuman theHuman;

#endif // CPLAYERHUMAN_H
