//https://en.wikipedia.org/wiki/Nine_men%27s_morris

#include <iostream>
#include "cBoard.h"

using namespace std;

int main()
{
    theBoard.Place( 10, eOccupant::black );
    theBoard.Place( 11, eOccupant::black );
    theBoard.Place( 12, eOccupant::black );

    theBoard.Display();

    return 0;
}
