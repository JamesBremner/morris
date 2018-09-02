#ifndef CBOARDGRAPH_H
#define CBOARDGRAPH_H
#include <nana/gui.hpp>
#include <cBoard.h>


class cBoardGraph : public cBoard
{
public:
    cBoardGraph();
    virtual ~cBoardGraph();

    void Draw( nana::paint::graphics & graph );

    int Index( pixel_t px, pixel_t py );

    bool Place( pixel_t px, pixel_t py, bool isWhite );

protected:

private:
    nana::paint::image myImage;
    int myGraphOffet;
    double myGraphScale;

    grid_t grid( pixel_t p );

    pixel_t pixel( grid_t g );
};

extern cBoardGraph theBoardGraph;

#endif // CBOARDGRAPH_H
