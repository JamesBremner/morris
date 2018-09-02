#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "cAutoPlayer.h"

cAutoPlayer::cAutoPlayer()
{
  /* initialize random seed: */
  srand (time(NULL));
}

cAutoPlayer::~cAutoPlayer()
{
    //dtor
}

 int cAutoPlayer::Play( cBoard * board )
 {
     int point;
     do {
        point = rand() % 24;
     } while ( board->Occupant( point ) != eOccupant::none );
     return point;
 }
