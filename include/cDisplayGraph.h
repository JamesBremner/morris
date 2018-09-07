#ifndef CDISPLAYGRAPH_H
#define CDISPLAYGRAPH_H

#include <cDisplay.h>


class cDisplayGraph : public cDisplay
{
    public:
        cDisplayGraph();
        virtual ~cDisplayGraph();

    void Update();
    void Sleep( int msecs );

    protected:

    private:
};

#endif // CDISPLAYGRAPH_H
