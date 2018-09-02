#include <iostream>

#include <nana/gui.hpp>
#include "cBoardGraph.h"
#include "cAutoPlayer.h"

using namespace nana;

cBoardGraph theBoard;
cAutoPlayer theAutoPlayer;
form fm;
drawing dw(fm);

int main()
{
    try
    {
        fm.caption("char-par");
        fm.size( size(712,714));
        fm.show();

        dw.draw([](nana::paint::graphics & graph)
        {
            theBoard.Draw( graph );
        });
        dw.update();

        fm.events().mouse_down([](const arg_mouse& arg)
        {
            bool mill = theBoard.Place(
                            (pixel_t)arg.pos.x,
                            (pixel_t)arg.pos.y,
                            false
                        );

            dw.update();

            if( mill )
            {
                msgbox mill("!!! MILL !!!");
                mill << "Player has achieved a mill";
                mill.show();
            }
            else
            {
                // computer plays
                bool mill = theBoard.Place(
                                theAutoPlayer.Play( (cBoard*)&theBoard ),
                                eOccupant::white );
                dw.update();
                if( mill )
                {
                    msgbox mill("!!! MILL !!!");
                    mill << "Computer has achieved a mill";
                    mill.show();
                }
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

