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
    // computer selects play
    int point = Play();
    theBoard.Place(
        point,
        eOccupant::white );
    if( theBoard.IsMill( point ) )
    {
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

    int point = -1;
    if( myLevel > 1 )
    {
        // foil any attempts to complete mill
        for( std::vector< cMill >::iterator iter = theBoard.begin_mill();
                iter != theBoard.end_mill(); iter++ )
        {
            point = iter->IsNearlyFull( eOccupant::black );
            if( point >= 0 )
                break;
        }
    }

    if( point < 0 )
    {
        // play on random empty point
        do
        {
            point = rand() % 24;
        }
        while ( theBoard.Occupant( point ) != eOccupant::none );
    }

    std::cout << "Computer " << point << "\n";
    return point;
}

void cPlayerAuto::Move()
{
    if( theBoard.PlayPhase() == cPhase::ePhase::moving_removing )
        return;
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
            ! theBoard.IsNext( src, dst ));
    std::cout << "Computer move " << src <<" "<< dst << "\n";
    theBoard.Move( dst, src );
    if( theBoard.IsMill( src ))
        RemoveOpponentPiece();
}

void cPlayerAuto::RemoveOpponentPiece()
{
    G.Message("!!! MILL !!!",
              "Computer has achieved a mill\n"
              "A red piece will be removed from board");
    int point;
    do
    {
        point = rand() % 24;
    }
    while( theBoard.Occupant( point ) != eOccupant::black );
    theBoard.Remove( point, eOccupant::black );
}
