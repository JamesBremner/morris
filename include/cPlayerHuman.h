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
            @param[in] click pixel position of destination
        */
        void Places( click_t click );

        void Remove( click_t click );

        void Move1( click_t click );

        /** complete move
            @param[in] click pixel position of destination
        */
        void Move2( click_t click  );

};

#endif // CPLAYERHUMAN_H
