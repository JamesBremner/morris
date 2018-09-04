#ifndef CPLAYERHUMAN_H
#define CPLAYERHUMAN_H
#include "cBoard.h"
#include "cPlayer.h"

class cPlayerHuman : public cPlayer
{
    public:
        cPlayerHuman();

        void Places( pixel_t x, pixel_t y );

    protected:

    private:
};

#endif // CPLAYERHUMAN_H
