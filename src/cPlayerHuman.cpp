#include "cBoardGraph.h"
#include "cPlayerHuman.h"
extern cBoardGraph G;

cPlayerHuman::cPlayerHuman()
{
    //ctor
}
void cPlayerHuman::Places( int point )
{
    if( theBoard.Occupant( point ) != eOccupant::none )
    {
        if( theBoard.Variant() != eVariant::lasker )
            return;
        else
        {
            if( theBoard.Occupant( point ) != eOccupant::black )
                return;
            Move1( point );
            return;
        }
    }

    // Place human's piece on board
    int ret = theBoard.Place(
                  point,
                  eOccupant::black
              );

    // check that click was on a point where piece could be placed
    if( ret == -1 )
    {
        return;
    }

    // check if mill was created
    if( theBoard.IsMill( point ) )
    {
        G.Message(
            "!!! MILL !!!",
            "Player has achieved a mill\n"
            "Click on blue piece to remove");
        theBoard.Action( cPhase::eAction::mill );
        return;
    }

    // check for remaining pieces
    if( ! Piece() )
    {
        G.Message("All Pieces played","");
        theBoard.Action( cPhase::eAction::all_played );
        return;
    }
}
void cPlayerHuman::Remove( int point )
{
    theBoard.Remove(
        point,
        eOccupant::white );
    theBoard.Action(
        cPhase::eAction::remove );
}

void cPlayerHuman::Move1( int point )
{
    if( theBoard.Occupant( point ) != eOccupant::black )
    {
        theBoard.Action( cPhase::eAction::fail );
        return;
    }
    theBoard.Select( point );
    theBoard.Action( cPhase::eAction::move_src );
}

void cPlayerHuman::Move2( int point )
{
    if( theBoard.Occupant( point ) != eOccupant::none )
    {
        theBoard.Action( cPhase::eAction::fail );
        return;
    }
    theBoard.Move( point );
    theBoard.Action( cPhase::eAction::move_dst );

    if( theBoard.IsMill( point ))
    {
        G.Message(
            "!!! MILL !!!",
            "Player has achieved a mill\n"
            "Click on blue piece to remove");
        theBoard.Action( cPhase::eAction::mill );
    }

    return;
}
