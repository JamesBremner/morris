#ifndef CMILL_H
#define CMILL_H

class cBoard;

class cMill
{
    public:
        cMill( int a, int b, int c );
        virtual ~cMill();
        bool Includes( int i );
        bool IsFull( eOccupant o, cBoard * board );
    protected:

    private:
        int myPoint[3];
};

#endif // CMILL_H
