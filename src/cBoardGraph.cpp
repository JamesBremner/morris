#include "cBoardGraph.h"
using namespace nana;

cBoardGraph::cBoardGraph()
    : myImage("Board.bmp")
    , myGraphOffet( 130)
    , myGraphScale( 75)
{
    if (myImage.empty())
    {
        msgbox err("Error");
        err << "Cannot read Board.bmp";
        err.show();
        exit(1);
    }
}

cBoardGraph::~cBoardGraph()
{
    //dtor
}

void cBoardGraph::Draw( nana::paint::graphics & graph )
{
    myImage.paste(graph, nana::point{} );

    for( auto p : myPoint )
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
}

bool cBoardGraph::Place( pixel_t px, pixel_t py, bool isWhite )
{
    eOccupant o = eOccupant::black;
    if( isWhite )
        o = eOccupant::white;
    return cBoard::Place( grid(px), grid(py), o );
}

int cBoardGraph::Index( pixel_t px, pixel_t py )
{
    return cBoard::Index( grid(px), grid(py) );
}
grid_t cBoardGraph::grid( pixel_t p )
{
    return round( (p-myGraphOffet) / myGraphScale );
}
pixel_t cBoardGraph::pixel( grid_t g )
{
    return myGraphOffet + myGraphScale * g;
}
