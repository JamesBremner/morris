#ifndef CBOARD_H
#define CBOARD_H
#include <vector>

typedef int pixel_t;
typedef int grid_t;

#include "cPoint.h"
#include "cMill.h"



class cBoard
{
public:
    cBoard();
    virtual ~cBoard();
    void Display();
    void Place( grid_t x, grid_t y, eOccupant o );
    int Index( grid_t x, grid_t y );
    void Place( int point, eOccupant o );
    bool IsMill( int point );
    eOccupant Occupant( int i )
    {
        return myPoint[i].Occupant();
    }
    std::vector< cPoint >::iterator begin()
    {
        return myPoint.begin();
    }
    std::vector< cPoint >::iterator end()
    {
        return myPoint.end();
    }

protected:

private:
    std::vector< cPoint > myPoint;
    std::vector< cMill > myMill;

};

extern cBoard theBoard;

#endif // CBOARD_H
