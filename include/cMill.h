#ifndef CMILL_H
#define CMILL_H


class cMill
{
    public:
        cMill( int a, int b, int c );
        virtual ~cMill();
        bool Includes( int i );
        bool IsFull( eOccupant o );
    protected:

    private:
        int myPoint[3];
};

#endif // CMILL_H
