#ifndef CAUTOPLAYER_H
#define CAUTOPLAYER_H
#include "cBoard.h"
#include "cPlayer.h"

/** An automatic player of the Nine Men's Morris game */
class cPlayerAuto : public cPlayer
{
    /** CTOR */
    public:
        cPlayerAuto();
        virtual ~cPlayerAuto();

    void Places();

    /** Select a point to place the next computer piece
        @return point ( 1 to 24 ) to play next piece

        Level 2: Foil opponent's attempt to build mill
        Level 1: The point is chosen at random from among the still empty points
    */
    int Play();

    /** Remove random opponent piece

    Called after computer achieves mill
    */
    void RemoveOpponentPiece();

    void Level( int l )
    {
        myLevel = l;
    }

    private:
        int myLevel;

};

#endif // CAUTOPLAYER_H
