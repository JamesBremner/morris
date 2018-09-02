#ifndef CPOINT_H
#define CPOINT_H
#include <iostream>
#include <vector>

enum class eOccupant
{
    none,
    white,
    black
};

class cPoint
{
    public:
        cPoint( int x, int y, int i );

        virtual ~cPoint();
        void Display();
        void Mark( std::vector< std::vector<char> >& a );
        bool Place( eOccupant o );
        bool IsOccupied()
        {
            return myOccupant != eOccupant::none;
        }
        eOccupant Occupant()
        {
            return myOccupant;
        }
        void get( grid_t& x, grid_t& y )
        {
            x = myX;
            y = myY;
        }
        int Index()
        {
            return myIndex;
        }
        void Clear()
        {
            myOccupant = eOccupant::none;
        }

    protected:

    private:
        int myX;        // x location on 7x7 board
        int myY;        // y location on 7x7 board
        int myIndex;
        eOccupant myOccupant;
};

#endif // CPOINT_H
