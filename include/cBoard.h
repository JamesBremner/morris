#ifndef CBOARD_H
#define CBOARD_H
#include <vector>

typedef int pixel_t;
typedef int grid_t;

#include "cPoint.h"
#include "cMill.h"

/** Nine Men's Morris board

    There are 24 positions where pieces can be placed
    The positions are located at certain intersection of a 7 by 7 grid

    <pre>
    1 . . 2 . . 3
    . 4 . 5 . 6 .
    . . 7 8 9 . .
    101123.131415
    . . 161718. .
    . 19. 20.21 .
    22. .23 . .24
    </pre>

*/

class cBoard
{
public:
    /** CTOR */
    cBoard();
    virtual ~cBoard();

    /** Text Display of state of play */
    void Display();

    /** Place a piece on an empty position
        @param[in] x grid location
        @param[in] y grid location
        @param[in] o color of piece
        @return true if placement creates a mill
    */
    bool Place( grid_t x, grid_t y, eOccupant o );

    /** Position index from grid location
        @param[in] x grid location
        @param[in] y grid location
        @return -1 if no position there
    */
    int Index( grid_t x, grid_t y );

    /** Place a piece on an empty position
        @param[in] point index of position, 1-based
        @param[in] o color of piece to be placed
        @return true if placement creates a mill

        If position already occupied, will be ignored
    */
    bool Place( int point, eOccupant o );

    /** True if board contains a mill ( three pieces in a line )
        @param[in] point index of position where piece was last placed - must be part of mill
        @return true if mill achieved with position
    */
    bool IsMill( int point );

    /** Color of piece occupying position
        @param[in] i index of position
    */
    eOccupant Occupant( int i )
    {
        return myPoint[i].Occupant();
    }

    /** Begin loop over positions */
    std::vector< cPoint >::iterator begin()
    {
        return myPoint.begin();
    }

    /** End loop over positions */
    std::vector< cPoint >::iterator end()
    {
        return myPoint.end();
    }

    /** Remove opponent's piece from board
        @param[in] point index of point containg piece to be removed
        @param[in] o color of piexe to be removed
        @return true if successfully removed

        Called after mill achieved.
        If point does not contain enemy piece, nothing happens
        except return false

    */
    bool Remove( int point, eOccupant o );


    /** Clear pieces, ready for new game */
    void Clear();

    int CountPieces();


protected:

    std::vector< cPoint > myPoint;
    std::vector< cMill > myMill;


};

extern cBoard theBoard;

#endif // CBOARD_H
