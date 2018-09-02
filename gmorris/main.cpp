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

        fm.events().mouse_down([](const arg_mouse& arg)
        {
            bool mill = G.Place(
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
                theBoard.Clear();
                dw.update();
            }
            else
            {
                // computer plays
                bool mill = G.Place(
                                theAutoPlayer.Play(),
                                eOccupant::white );
                dw.update();
                if( mill )
                {
                    msgbox mill("!!! MILL !!!");
                    mill << "Computer has achieved a mill";
                    mill.show();
                    theBoard.Clear();
                    dw.update();
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

