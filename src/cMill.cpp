#include <iostream>
#include "cBoard.h"
#include "cMill.h"

cMill::cMill(int a, int b, int c )
{
    myPoint[0] = a-1;
    myPoint[1] = b-1;
    myPoint[2] = c-1;
}

bool cMill::Includes( int i )
{
    for( int ip : myPoint )
        if( i == ip )
            return true;
    return false;
}
bool cMill::IsFull( eOccupant o )
{
    for( int k = 0; k< 3; k++ )
    if( theBoard.Occupant( myPoint[k] ) != o )
        return false;
    for( int k = 0; k< 3; k++ )
        std::cout << myPoint[k] << " ";
    std::cout << "\n";
    return true;
}

cMill::~cMill()
{
    //dtor
}
