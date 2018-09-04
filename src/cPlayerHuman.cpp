#include "cBoardGraph.h"
#include "cPlayerHuman.h"
extern cBoardGraph G;

cPlayerHuman::cPlayerHuman()
{
    //ctor
}
void cPlayerHuman::Places( pixel_t x, pixel_t y )
{
    // Place human's piece on board
    int ret = G.Place(
                  x,
                  y,
                  eOccupant::black
              );

    // check that click was on a point where piece could be placed
    if( ret == -1 )
    {
        return;
    }

    // check if mill was created
    if( ret == 99 )
    {
        G.Message(
            "!!! MILL !!!",
            "Player has achieved a mill\n"
            "Click on blue piece to remove");
        theBoard.PlayPhase( ePlayPhase::placing_removing );
        return;
    }

    // check for remaining pieces
    if( ! Piece() )
    {
        G.Message("All Pieces played","");
        theBoard.PlayPhase( ePlayPhase::moving );
        return;
    }
}
