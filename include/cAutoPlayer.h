#ifndef CAUTOPLAYER_H
#define CAUTOPLAYER_H
#include "cBoard.h"

/** An automatic player of the Nine Men's Morris game */
class cAutoPlayer
{
    /** CTOR */
    public:
        cAutoPlayer();
        virtual ~cAutoPlayer();

    /** Select a legal random point to place the next computer piece
        @return point ( 1 to 24 ) to play next piece

        The point is chosen at random from among the still empty points
    */
    int Play();

};

#endif // CAUTOPLAYER_H
