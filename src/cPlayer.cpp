#include "cPlayer.h"

cPlayer::cPlayer()
 : myPieces( 9 )
{
    //ctor
}

cPlayer::~cPlayer()
{
    //dtor
}

bool cPlayer::Piece()
{
    myPieces--;
    if( myPieces <= 0 )
        return false;
    return true;
}
