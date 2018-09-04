#ifndef CBOARDGRAPH_H
#define CBOARDGRAPH_H
#include <nana/gui.hpp>
#include <cBoard.h>

/** Morris board for GUI applications */
class cBoardGraph
{
public:
    cBoardGraph( nana::drawing& dw);
    virtual ~cBoardGraph();

    void Draw( nana::paint::graphics & graph );

    int Index( pixel_t px, pixel_t py );

    /** Place piece on point clicked
        @param[in] px x pixel location
        @param[in] py y pixel location
        @param[in] o piece to place
        @return 0 to 23 point index where piece placed
        @return -1 no point at location
        @return 99 mill created
    */
    int Place(
        pixel_t px,
        pixel_t py,
        eOccupant o );

    bool Place( int point, eOccupant o )
    {
        return theBoard.Place( point, o );
    }
    bool Remove( pixel_t px, pixel_t py, eOccupant o );

    void Message(
                 const std::string& title,
                 const std::string& text);

protected:

private:
    nana::paint::image myImage;
    nana::drawing& myDrawing;
    int myGraphOffet;
    double myGraphScale;

    grid_t grid( pixel_t p );

    pixel_t pixel( grid_t g );
};

#endif // CBOARDGRAPH_H
