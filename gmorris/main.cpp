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
            click_t click(
                (pixel_t)arg.pos.x,
                (pixel_t)arg.pos.y );

            switch( theBoard.PlayPhase() )
            {
            case ePlayPhase::placing:
            {
                theHuman.Places( click );
                dw.update();

                theAutoPlayer.Places();
                dw.update();
            }
            break;

            case ePlayPhase::placing_removing:
            {
                theHuman.Remove( click );
                dw.update();

                theAutoPlayer.Places();
                dw.update();
            }
            break;

            case ePlayPhase::moving:
            {
                theHuman.Move1( click );
                dw.update();

                theAutoPlayer.Move();
                dw.update();
            }
            break;

            case ePlayPhase::moving_destination:
            {
                theHuman.Move2( click );
                dw.update();

                theAutoPlayer.Move();
                dw.update();
            }
            break;

            case ePlayPhase::moving_removing:
            {
                theHuman.Remove( click );
                dw.update();

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

