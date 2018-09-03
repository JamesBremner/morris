#include <iostream>

#include <nana/gui.hpp>
#include "cBoardGraph.h"
#include "cAutoPlayer.h"

using namespace nana;

cBoardGraph G;
cPlayer theHuman;
cPlayerAuto theAutoPlayer;
form fm;
drawing dw(fm);

void HumanPlaces( pixel_t x, pixel_t y )
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

    dw.update();

    // check if mill was created
    if( ret == 99 )
    {
        msgbox mill("!!! MILL !!!");
        mill << "Player has achieved a mill\n"
             "Click on blue piece to remove";
        mill.show();
        theBoard.PlayPhase( ePlayPhase::placing_removing );
        dw.update();
        return;
    }

    // check for remaining pieces
    if( ! theHuman.Piece() )
    {
        msgbox msg("All Pieces played");
        msg.show();
        theBoard.PlayPhase( ePlayPhase::moving );

        // Clear out, ready for new game
//                    theBoard.Clear();
//                    theHuman.Clear();
//                    theAutoPlayer.Clear();
//                    dw.update();
        return;
    }


}

int main()
{
    try
    {
        fm.caption("char-par");
        fm.size( size(712,714));
        fm.show();
        //theAutoPlayer.Level( 1 );

        dw.draw([](nana::paint::graphics & graph)
        {
            G.Draw( graph );
        });
        dw.update();

        fm.events().mouse_down([](const arg_mouse& arg)
        {
            switch( theBoard.PlayPhase() )
            {
            case ePlayPhase::placing:
            {
                HumanPlaces(
                    (pixel_t)arg.pos.x,
                    (pixel_t)arg.pos.y );

                // computer plays
                int ret = G.Place(
                          theAutoPlayer.Play(),
                          eOccupant::white );
                dw.update();
                if( ret == 99 )
                {
                    msgbox mill("!!! MILL !!!");
                    mill << "Computer has achieved a mill\n"
                         "A red piece will be removed from board";
                    mill.show();
                    theAutoPlayer.RemoveOpponentPiece();
                    dw.update();
                }
            }
            break;

            case ePlayPhase::placing_removing:
            {
                G.Remove(
                    (pixel_t)arg.pos.x,
                    (pixel_t)arg.pos.y,
                    eOccupant::white );
                theBoard.PlayPhase( ePlayPhase::placing );
                dw.update();
            }
            break;

            case ePlayPhase::moving:
            {
                int point = G.Index( (pixel_t)arg.pos.x,
                                     (pixel_t)arg.pos.y);
                if( theBoard.Occupant( point ) != eOccupant::black )
                    return;
                theBoard.Select( G.Index( (pixel_t)arg.pos.x,
                                          (pixel_t)arg.pos.y));
                theBoard.PlayPhase( ePlayPhase::moving_destination );
                dw.update();
            }
            break;

            case ePlayPhase::moving_destination:
            {
                int point = G.Index( (pixel_t)arg.pos.x,
                                     (pixel_t)arg.pos.y);
                if( theBoard.Occupant( point ) != eOccupant::none )
                    return;
                theBoard.Move( point );
                theBoard.PlayPhase( ePlayPhase::moving );
                dw.update();
            }
            break;
            }
        });

        exec();
    }
    catch( std::runtime_error& e )
    {
        msgbox mb( e.what() );
        mb();
    }
}

