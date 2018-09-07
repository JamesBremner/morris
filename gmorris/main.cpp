#include <iostream>

#include <nana/gui.hpp>
#include "cBoardGraph.h"
#include "cAutoPlayer.h"
#include "cPlayerHuman.h"
#include "cDisplayGraph.h"

using namespace nana;

form fm;
drawing dw(fm);
cDisplayGraph theDisplay;
cBoard theBoard( &theDisplay );
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

        dw.draw([](nana::paint::graphics & graph)
        {
            G.Draw( graph );
        });
        dw.update();

        G.Configure( fm );

        fm.events().mouse_down([](const arg_mouse& arg)
        {
            G.Click( arg );
        });

        exec();
    }
    catch( std::runtime_error& e )
    {
        msgbox mb( e.what() );
        mb();
    }
}

