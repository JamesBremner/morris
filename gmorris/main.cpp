#include <iostream>
#include <math.h>
#include <nana/gui.hpp>
#include "cBoard.h"

using namespace nana;

form fm;
drawing dw(fm);

grid_t grid( pixel_t p )
{
    return round( (p-130) / 75.0 );
}
pixel_t pixel( grid_t g )
{
    return 130 + 75 * g;
}

int main()
{
    try
    {
        fm.caption("char-par");
        fm.size( size(712,714));
        fm.show();

        nana::paint::image img("Board.bmp");

        dw.draw([&img](nana::paint::graphics & graph)
        {
            if (img.empty())
            {
                msgbox err("Error");
                err.show();
                return;
            }
            img.paste(graph, nana::point{} );

            for( auto p : theBoard )
            {
                color c = colors::black;
                switch( p.Occupant() )
                {
                case eOccupant::black:
                    c = colors::red;
                    break;
                case eOccupant::white:
                    c = colors::blue;
                    break;
                }
                if( c == colors::black )
                    continue;

                grid_t gx, gy;
                p.get( gx, gy );
                graph.rectangle( rectangle( pixel(gx)-5,pixel(gy)-5,10,10),true,c);
            }
        });
        dw.update();

        fm.events().mouse_down([](const arg_mouse& arg)
        {
            int x = arg.pos.x;
            int y =  arg.pos.y;
            eOccupant o = eOccupant::black;
            if( ! arg.left_button )
                o = eOccupant::white;
//            grid_t gx = grid( (pixel_t)x);
//            grid_t gy = grid( (pixel_t)y);
//             std::cout<<  x <<" "<< y <<" "<< (int)gx <<" " << (int)gy << "\n";
//            std::cout << arg.left_button <<" "<< arg.right_button <<" "<< arg.mid_button << "\n";

            theBoard.Place(
                grid( (pixel_t)x),
                grid( (pixel_t)y),
                o
            );

            dw.update();

            if( theBoard.IsMill( theBoard.Index(
                                     grid( (pixel_t)x),
                                     grid( (pixel_t)y)) ) )
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

