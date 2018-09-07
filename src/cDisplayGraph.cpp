#include <nana/gui.hpp>
#include <nana/system/platform.hpp>
#include "cDisplayGraph.h"


cDisplayGraph::cDisplayGraph()
{
    //ctor
}

cDisplayGraph::~cDisplayGraph()
{
    //dtor
}

void cDisplayGraph::Update()
{
    extern nana::drawing dw;
    dw.update();
}

void cDisplayGraph::Sleep( int msecs )
{
    nana::system::sleep( msecs );
}
