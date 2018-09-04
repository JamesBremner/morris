#ifndef CPLAYERHUMAN_H
#define CPLAYERHUMAN_H
#include "cBoard.h"
#include "cPlayer.h"

/** Human Player */
class cPlayerHuman : public cPlayer
{
    public:
        cPlayerHuman();

        /** Place a piece
            @param[in] x pixel position of destination
            @param[in] y pixel position of destination
        */
        void Places( pixel_t x, pixel_t y );

        /** complete move
            @param[in] x pixel position of destination
            @param[in] y pixel position of destination
        */
        void Move2( pixel_t x, pixel_t y );

};

#endif // CPLAYERHUMAN_H
