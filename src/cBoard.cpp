#include <iostream>
#include <math.h>
#include "cBoard.h"

cBoard theBoard;

cBoard::cBoard()
{
    // Construct the points on grid intersections
    ConstructThreePoints( 0, 0, 3 );
    ConstructThreePoints( 1, 1, 2 );
    ConstructThreePoints( 2, 2, 1 );
    ConstructThreePoints( 0, 3, 1 );
    ConstructThreePoints( 4, 3, 1 );
    ConstructThreePoints( 2, 4, 1 );
    ConstructThreePoints( 1, 5, 2 );
    ConstructThreePoints( 0, 6, 3 );

    // construct possible vertical mills on point indices

    myMill.push_back( cMill(1,10,22));
    myMill.push_back( cMill(4,11,19));
    myMill.push_back( cMill(7,12,16));
    myMill.push_back( cMill(2,5,8));
    myMill.push_back( cMill(17,20,23));
    myMill.push_back( cMill(9,13,18));
    myMill.push_back( cMill(6,14,21));
    myMill.push_back( cMill(3,15,24));

    Clear();
}

cBoard::~cBoard()
{
    //dtor
}

void cBoard::ConstructThreePoints(
    int x,
    int y,
    int xinc )
{
    myPoint.push_back( cPoint( x, y, myPoint.size() ));
    x += xinc;
    myPoint.push_back( cPoint( x, y, myPoint.size() ));
    x += xinc;
    myPoint.push_back( cPoint( x, y, myPoint.size() ));

    int last = myPoint.size();
    myMill.push_back( cMill( last-2, last-1, last ));
}

void cBoard::Variant( const std::string& var )
{
    if( var == "Standard" )
        myVariant = eVariant::standard;
    if( var == "Lasker" )
        myVariant = eVariant::lasker;
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
    if( 0 > point || point > 23 )
        return false;
    myPoint[ point ].Place( o );
    return true;
}

bool cBoard::IsMill( int point )
{
    for( cMill mill : myMill )
    {
        if( ! mill.Includes( point ))
            continue;
        if( mill.IsFull( this->Occupant( point ) ))
            return true;
    }
    return false;
}

bool cBoard::Place( grid_t x, grid_t y, eOccupant o )
{
    // convert grid location to point index
    int point = Index( x, y );

    // check there is a point at the grid location
    if( point < 0 )
        return false;

    // place the piece
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

bool cBoard::Remove( int point, eOccupant o )
{
    if( myPoint[ point ].Occupant() != o )
        return false;
    myPoint[ point ].Clear();
    std::cout << "removed " << point << "\n";
    return true;

}

void cBoard::Move( int point )
{
    if( 0 > point || point > 23 )
        return;
    if( 0 > mySelected || mySelected > 23 )
        return;
    myPoint[ point ].Place( myPoint[ mySelected].Occupant() );
    myPoint[ mySelected ].Clear();
}

void cBoard::Move( int dst, int src )
{
    if( 0 > dst || dst > 23 )
        return;
    if( 0 > src || src > 23 )
        return;
    if( Occupant(dst) != eOccupant::none )
        return;
    myPoint[ dst ].Place( myPoint[ src].Occupant() );
    myPoint[ src ].Clear();
}

void cBoard::Clear()
{
    for( cPoint& p : myPoint )
    {
        p.Clear();
    }
    myPhase.Clear();
    mySelected = -1;
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

bool cBoard::IsNext( int a, int b )
{
    for( cMill mill : myMill )
    {
        if( mill.IsNext(a,b))
            return true;
    }
    return false;
}

