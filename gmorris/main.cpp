#include <iostream>

#include <nana/gui.hpp>
#include "cBoardGraph.h"
#include "cAutoPlayer.h"

using namespace nana;

cBoardGraph G;
cAutoPlayer theAutoPlayer;
form fm;
drawing dw(fm);

int main()
{
    eOccupant removing = eOccupant::none;

    try
    {
        fm.caption("char-par");
        fm.size( size(712,714));
        fm.show();

        dw.draw([](nana::paint::graphics & graph)
        {
            G.Draw( graph );
        });
        dw.update();

        fm.events().mouse_down([&removing](const arg_mouse& arg)
        {
            if( removing == eOccupant::none )
            {
                // Place human's piece on board
                int ret = G.Place(
                            (pixel_t)arg.pos.x,
                            (pixel_t)arg.pos.y,
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
                    removing = eOccupant::white;
                    dw.update();
                }
                else
                {
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
            }
            else
            {
                G.Remove(
                    (pixel_t)arg.pos.x,
                    (pixel_t)arg.pos.y,
                    removing );
                removing = eOccupant::none;
                dw.update();
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

