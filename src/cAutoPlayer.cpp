#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdexcept>
#include "cBoardGraph.h"
#include "cAutoPlayer.h"
extern cBoardGraph G;

cPlayerAuto::cPlayerAuto()
    : myLevel( 2 )
{
    /* initialize random seed: */
    srand (time(NULL));
}

cPlayerAuto::~cPlayerAuto()
{
    //dtor
}

void cPlayerAuto::Places()
{
    // computer plays
    int ret = G.Place(
                  Play(),
                  eOccupant::white );
    if( ret == 99 )
    {
        G.Message("!!! MILL !!!",
                  "Computer has achieved a mill\n"
                  "A red piece will be removed from board");
        RemoveOpponentPiece();
    }
}

int cPlayerAuto::Play( )
{
//    // check that there are more piece to play
//    if( ! Piece() )
//    {
//        throw std::runtime_error( "Computer has no more pieces" );
//    }

    if( myLevel > 1 )
    {
        // foil any attempts to complete mill
        for( std::vector< cMill >::iterator iter = theBoard.begin_mill();
                iter != theBoard.end_mill(); iter++ )
        {
            int point = iter->IsNearlyFull( eOccupant::black );
            if( point == -1 )
                continue;
            return point;
        }
    }

    // play on random empty point
    int point;
    do
    {
        point = rand() % 24;
    }
    while ( theBoard.Occupant( point ) != eOccupant::none );
    return point;
}

void cPlayerAuto::Move()
{
    int src, dst;
    do
    {
        do
        {
            src = rand() % 24;
        }
        while ( theBoard.Occupant( src ) != eOccupant::white );
        dst = rand() % 24;
    }
    while( theBoard.Occupant( dst ) != eOccupant::none &&
          theBoard.IsNext( src, dst ));
    theBoard.Move( dst, src );
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
