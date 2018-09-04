#include "cBoardGraph.h"
#include "cPlayerHuman.h"
extern cBoardGraph G;

cPlayerHuman::cPlayerHuman()
{
    //ctor
}
void cPlayerHuman::Places( click_t click )
{
    // Place human's piece on board
    int ret = G.Place(
                  click.first,
                  click.second,
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
void cPlayerHuman::Remove(click_t click )
{
    G.Remove(
        click.first,
        click.second,
        eOccupant::white );
    if( theBoard.PlayPhase() == ePlayPhase::placing_removing)
        theBoard.PlayPhase( ePlayPhase::placing );
    else
        theBoard.PlayPhase( ePlayPhase::moving );
}

void cPlayerHuman::Move1( click_t click )
{
    int point = G.Index(
                    click.first,
                    click.second );
    if( theBoard.Occupant( point ) != eOccupant::black )
        return;
    theBoard.Select( point );
    theBoard.PlayPhase( ePlayPhase::moving_destination );
}

void cPlayerHuman::Move2( click_t click )
{
    int point = G.Index(
                    click.first,
                    click.second );
    if( theBoard.Occupant( point ) != eOccupant::none )
    {
        theBoard.PlayPhase( ePlayPhase::moving );
        return;
    }
    theBoard.Move( point );

    if( theBoard.IsMill( point ))
    {
        G.Message(
            "!!! MILL !!!",
            "Player has achieved a mill\n"
            "Click on blue piece to remove");
        theBoard.PlayPhase( ePlayPhase::moving_removing );
        return;
    }

    theBoard.PlayPhase( ePlayPhase::moving );
    return;
}
