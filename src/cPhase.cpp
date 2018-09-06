#include <stdexcept>
#include "cPhase.h"
#include "cBoard.h"

cPhase::cPhase()
{
    //ctor
}

void cPhase::Clear()
{
    if( theBoard.Variant() == eVariant::lasker )
        myPhase = ePhase::lasker;
    else
        myPhase = ePhase::placing;
}

void cPhase::Action( eAction A )
{
    ePhase prev = myPhase;
    myPhase = ePhase::none;
    switch( prev )
    {
    case ePhase::placing:
    {
        switch( A )
        {
        case eAction::mill:
            myPhase = ePhase::placing_removing;
            break;
        case eAction::all_played:
            myPhase = ePhase::moving;
            break;
        }
    }
    break;

    case ePhase::placing_removing:
    {
        switch( A )
        {
        case eAction::remove:
            myPhase = ePhase::placing;
            break;
        }
    }
    break;

    case ePhase::moving_removing:
    {
        switch( A )
        {
        case eAction::remove:
            myPhase = ePhase::moving;
            break;
        }
    }
    break;

    case ePhase::moving:
    {
        switch( A )
        {
        case eAction::move_src:
            myPhase = ePhase::moving_destination;
            break;
        }
    }
    break;

    case ePhase::moving_destination:
    {
        switch( A )
        {
        case eAction::move_dst:
            myPhase = ePhase::moving;
            break;
        }
    }
    break;
    }

    std::cout << "Phase " << (int)A <<" "
              << (int)prev <<" "<< (int)myPhase << "\n";

    if( myPhase == ePhase::none )
    {
        throw std::runtime_error("cPhase::Action error");
    }
}
