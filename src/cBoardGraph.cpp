#include "cBoardGraph.h"
#include "cAutoPlayer.h"
#include "cPlayerHuman.h"
#include <nana/system/platform.hpp>
using namespace nana;

cBoardGraph::cBoardGraph( drawing& dw )
    : myImage("Board.bmp")
    , myGraphOffet( 130)
    , myGraphScale( 75)
    , myDrawing( dw )
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
    // Display board image
    myImage.paste(graph, nana::point{} );

    // loop over points
    for( auto p : theBoard )
    {
        // find color of piece on point
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

        // check for no piece
        if( c == colors::black )
            continue;

        // display piece
        grid_t gx, gy;
        p.get( gx, gy );
        graph.round_rectangle(
            rectangle( pixel(gx)-10,pixel(gy)-10,20,20),
            10, 10,
            c, true, c );

        if( p.Index() == theBoard.Select() )
        {
            graph.line(point(pixel(gx)-10,pixel(gy)-10),
                       point(pixel(gx)+10,pixel(gy)+10),
                       colors::white );
            graph.line(point(pixel(gx)+10,pixel(gy)-10),
                       point(pixel(gx)-10,pixel(gy)+10),
                       colors::white );
        }
    }
}

void cBoardGraph::Configure( form& fm )
{
    inputbox inbox(fm,"","");
    inputbox::text variant("Variant",std::vector<std::string> {"Standard","Lasker"});
    inputbox::text level("Computer Opponent Level",std::vector<std::string> {"1","2"});
    if( ! inbox.show( variant, level ) )
        exit(1);
    theBoard.Variant( variant.value() );
    theAutoPlayer.Level( atoi( level.value().c_str() ) );
}

void cBoardGraph::Click( const arg_mouse& arg )
{
    extern drawing dw;

    click_t click(
        (pixel_t)arg.pos.x,
        (pixel_t)arg.pos.y );

    switch( theBoard.PlayPhase() )
    {
    case cPhase::ePhase::placing:
    case cPhase::ePhase::lasker:
    {
        theHuman.Places( click );
        dw.update();

        theAutoPlayer.Places();
        dw.update();
    }
    break;

    case cPhase::ePhase::placing_removing:
    {
        theHuman.Remove( click );
        dw.update();
        nana::system::sleep( 1000 );

        theAutoPlayer.Places();
        dw.update();
    }
    break;

    case cPhase::ePhase::moving:
    {
        theHuman.Move1( click );
        dw.update();
    }
    break;

    case cPhase::ePhase::moving_destination:
    {
        theHuman.Move2( click );
        dw.update();

        theAutoPlayer.Move();
        dw.update();
    }
    break;

    case cPhase::ePhase::moving_removing:
    {
        theHuman.Remove( click );
        dw.update();

        theAutoPlayer.Move();
        dw.update();
    }
    break;
    }
}

int cBoardGraph::Place( pixel_t px, pixel_t py, eOccupant o )
{
    // convert from pixel location to point index
    int point = Index( px, py );

    // check there was a point at the location clicked
    if( point < 0 )
        return -1;

    // place the piece
    if( ! theBoard.Place( point, o ) )
        return -1;

    // return point where piece placed
    return point;
}

bool cBoardGraph::Remove( pixel_t px, pixel_t py, eOccupant o )
{
    return theBoard.Remove(
               Index( px, py),
               o );
}

int cBoardGraph::Index( pixel_t px, pixel_t py )
{
    return theBoard.Index( grid(px), grid(py) );
}
grid_t cBoardGraph::grid( pixel_t p )
{
    return round( (p-myGraphOffet) / myGraphScale );
}
pixel_t cBoardGraph::pixel( grid_t g )
{
    return myGraphOffet + myGraphScale * g;
}

void cBoardGraph::Message(
    const std::string& title,
    const std::string& text)
{
    myDrawing.update();
    msgbox msg( title );
    msg << text;
    msg.show();
}
