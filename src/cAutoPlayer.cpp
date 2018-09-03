#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "cAutoPlayer.h"

cPlayerAuto::cPlayerAuto()
{
    /* initialize random seed: */
    srand (time(NULL));
}

cPlayerAuto::~cPlayerAuto()
{
    //dtor
}

int cPlayerAuto::Play( )
{
    if( ! Piece() )
    {
        std::cout << "Computer has no more pieces\n";
    }
    int point;
    do
    {
        point = rand() % 24;
    }
    while ( theBoard.Occupant( point ) != eOccupant::none );
    return point;
}

void cPlayerAuto::RemoveOpponentPiece()
{
    int point;
    do
    {
        point = rand() % 24;
    }
    while( theBoard.Occupant( point ) != eOccupant::black );
        theBoard.Remove( point, eOccupant::black );
}
