#ifndef CAUTOPLAYER_H
#define CAUTOPLAYER_H
#include "cBoard.h"

class cAutoPlayer
{
    public:
        cAutoPlayer();
        virtual ~cAutoPlayer();

    int Play( cBoard * board );

    protected:

    private:
};

#endif // CAUTOPLAYER_H
