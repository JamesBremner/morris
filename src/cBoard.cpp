#include <iostream>
#include <math.h>
#include "cBoard.h"

cBoard theBoard;

cBoard::cBoard()
{
    // Construct the points on grid intersections
    int index = 0;
    myPoint.push_back( cPoint( 0,0, index++ ));
    myPoint.push_back( cPoint( 3,0, index++  ));
    myPoint.push_back( cPoint( 6,0, index++  ));
    myPoint.push_back( cPoint( 1,1, index++  ));
    myPoint.push_back( cPoint( 3,1, index++  ));
    myPoint.push_back( cPoint( 5,1, index++  ));
    myPoint.push_back( cPoint( 2,2, index++  ));
    myPoint.push_back( cPoint( 3,2, index++  ));
    myPoint.push_back( cPoint( 4,2, index++  ));
    myPoint.push_back( cPoint( 0,3, index++  ));
    myPoint.push_back( cPoint( 1,3, index++  ));
    myPoint.push_back( cPoint( 2,3, index++  ));
    myPoint.push_back( cPoint( 4,3, index++  ));
    myPoint.push_back( cPoint( 5,3, index++  ));
    myPoint.push_back( cPoint( 6,3, index++  ));
    myPoint.push_back( cPoint( 2,4, index++  ));
    myPoint.push_back( cPoint( 3,4, index++  ));
    myPoint.push_back( cPoint( 4,4, index++  ));
    myPoint.push_back( cPoint( 1,5, index++  ));
    myPoint.push_back( cPoint( 3,5, index++  ));
    myPoint.push_back( cPoint( 5,5, index++  ));
    myPoint.push_back( cPoint( 0,6, index++  ));
    myPoint.push_back( cPoint( 3,6, index++  ));
    myPoint.push_back( cPoint( 6,6, index++  ));

    // construct possible mills on point indices
    myMill.push_back( cMill(1,2,3));
    myMill.push_back( cMill(4,5,6));
    myMill.push_back( cMill(7,8,9));
    myMill.push_back( cMill(10,11,12));
    myMill.push_back( cMill(13,14,15));
    myMill.push_back( cMill(16,17,18));
    myMill.push_back( cMill(19,20,21));
    myMill.push_back( cMill(22,23,24));

    myMill.push_back( cMill(1,10,22));
    myMill.push_back( cMill(4,11,19));
    myMill.push_back( cMill(7,12,16));
    myMill.push_back( cMill(2,5,8));
    myMill.push_back( cMill(17,20,23));
    myMill.push_back( cMill(9,13,18));
    myMill.push_back( cMill(6,14,21));
    myMill.push_back( cMill(3,15,24));
}

cBoard::~cBoard()
{
    //dtor
}

void cBoard::Display()
{
    std::vector< std::vector<char> > a(7, std::vector<char>(7,' ') );
    for( cPoint& p : myPoint )
    {
        p.Mark( a );
    }
    for( auto& row : a )
    {
        for( char c : row )
        {
            std::cout << c << " ";
        }
        std::cout << "\n\n";
    }
}

bool cBoard::Place( int point, eOccupant o )
{
    myPoint[ point-1 ].Place( o );
    if( IsMill( point-1 )) {
        std::cout << "!!! MILL !!!\n";
        return true;
    }
    return false;
}

bool cBoard::IsMill( int point )
{
    for( cMill mill : myMill )
    {
        if( ! mill.Includes( point ))
            continue;
        if( mill.IsFull( this->Occupant( point ),this ))
            return true;
    }
    return false;
}

bool cBoard::Place( grid_t x, grid_t y, eOccupant o )
{
    int point = Index( x, y ) + 1;
    if( point < 0 )
        return false;
    return Place( point, o );
}

int cBoard::Index( grid_t x, grid_t y )
{
    for( cPoint p : myPoint )
    {
        grid_t px, py;
        p.get( px, py );
        if( px == x && py == y )
            return p.Index();
    }
    return -1;
}

void cBoard::Clear()
{
    for( cPoint& p : myPoint )
    {
        p.Clear();
    }
}

 int cBoard::CountPieces()
 {
     int count = 0;
         for( cPoint p : myPoint )
    {
        if( p.Occupant() != eOccupant::none )
            count++;
       // std::cout << (int)p.Occupant();
    }
    //std::cout << "\n";
    return count;
 }

