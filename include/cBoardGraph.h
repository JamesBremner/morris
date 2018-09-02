#ifndef CBOARDGRAPH_H
#define CBOARDGRAPH_H
#include <nana/gui.hpp>
#include <cBoard.h>

/** Morris board for GUI applications */
class cBoardGraph
{
public:
    cBoardGraph();
    virtual ~cBoardGraph();

    void Draw( nana::paint::graphics & graph );

    int Index( pixel_t px, pixel_t py );

    bool Place( pixel_t px, pixel_t py, bool isWhite );
    bool Place( int point, eOccupant o )
    {
        return theBoard.Place( point, o );
    }

protected:

private:
    nana::paint::image myImage;
    int myGraphOffet;
    double myGraphScale;

    grid_t grid( pixel_t p );

    pixel_t pixel( grid_t g );
};

#endif // CBOARDGRAPH_H
