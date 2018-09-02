#include <iostream>

#include <nana/gui.hpp>
#include "cBoardGraph.h"

using namespace nana;

cBoardGraph theBoard;
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
                            arg.left_button
                        );

            dw.update();

            if( mill )
            {
                msgbox mill("!!! MILL !!!");
                mill.show();
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

