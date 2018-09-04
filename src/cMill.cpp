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

int cMill::IsNearlyFull( eOccupant o )
{
    int count = 0;
    int empty = -1;
    for( int k = 0; k< 3; k++ )
    {
        eOccupant actual = theBoard.Occupant( myPoint[k] );
        if( actual == o )
        {
            count++;
            continue;
        }
        if( actual == eOccupant::none)
        {
            empty = myPoint[k];
            continue;
        }
        return -1;
    }
    if ( count == 2 )
        return empty;
    return -1;
}
bool cMill::IsNext( int a, int b )
{
    if( ! Includes( a ))
        return false;
    if( ! Includes( b ))
        return false;
    if(
        (myPoint[0] == a && myPoint[1] == b ) ||
        (myPoint[0] == b && myPoint[1] == a ) ||
        (myPoint[1] == a && myPoint[2] == b ) ||
        (myPoint[1] == b && myPoint[2] == a )
    )
        return true;
    return false;
}

cMill::~cMill()
{
    //dtor
}
