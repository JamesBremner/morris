#include <iostream>

#include <nana/gui.hpp>
#include "cBoardGraph.h"
#include "cAutoPlayer.h"
#include "cPlayerHuman.h"

using namespace nana;

form fm;
drawing dw(fm);
cBoardGraph G( dw );
cPlayerHuman theHuman;
cPlayerAuto theAutoPlayer;


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
                theHuman.Places(
                    (pixel_t)arg.pos.x,
                    (pixel_t)arg.pos.y );
                dw.update();

                theAutoPlayer.Places();
                dw.update();
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

                theAutoPlayer.Places();
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
                // human player has selected destination for move
                theHuman.Move2((pixel_t)arg.pos.x,
                               (pixel_t)arg.pos.y);
                dw.update();

                // if human move did not complete a mill, computer gets a move
                if( theBoard.PlayPhase() != ePlayPhase::moving_removing )
                {
                    theAutoPlayer.Move();
                    dw.update();
                }
            }
            break;

            case ePlayPhase::moving_removing:
            {
                // human player has selected computer's piece to remove
                G.Remove(
                    (pixel_t)arg.pos.x,
                    (pixel_t)arg.pos.y,
                    eOccupant::white );
                theBoard.PlayPhase( ePlayPhase::moving );
                dw.update();

                // computer moves
                theAutoPlayer.Move();
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

