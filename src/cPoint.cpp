#include <iostream>

#include "cBoard.h"

cPoint::cPoint( int x, int y, int i )
    : myX(x)
    , myY(y)
    , myIndex( i )
    , myOccupant( eOccupant::none )
{
}

cPoint::~cPoint()
{
    //dtor
}
void cPoint::Display()
{
    std::cout << myX <<" "<< myY <<"\n";
}

void cPoint::Mark( std::vector< std::vector<char> >& a )
{
    char c;
    switch( myOccupant )
    {
    case eOccupant::none:
        c = (char)('a' + myIndex);
        break;
    case eOccupant::black:
        c = 'B';
        break;
    case eOccupant::white:
        c = 'W';
        break;
    }

    a[myY][myX] = c;
}
bool cPoint::Place( eOccupant o)
{
    if( IsOccupied() )
        return false;
    myOccupant = o;
    return true;
}

