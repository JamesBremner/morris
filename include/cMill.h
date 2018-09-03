#ifndef CMILL_H
#define CMILL_H

class cBoard;

class cMill
{
    public:
        /** CTOR
            @param[in] a point index, 1-based
            @param[in] b point index, 1-based
            @param[in] c point index, 1-based
        */
        cMill( int a, int b, int c );

        virtual ~cMill();

        /** True if mill includes point
            @param[in] i point index to check for inclusion, 0-based
        */
        bool Includes( int i );

        /** True if mill is complete, with pieces of specified color
            @param[in] o color of pieces to be checked for completing mill
        */
        bool IsFull( eOccupant o );

        /** Check for mill nearly full with opponent's pieces
            @param[in] o color of opponent's pieces
            @return -1 mill is not nearly full
            @return 0 to 23 index of one point still empty
        */
        int IsNearlyFull( eOccupant o );

    private:
        int myPoint[3];
};

#endif // CMILL_H
