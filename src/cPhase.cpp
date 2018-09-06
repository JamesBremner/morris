#include <stdexcept>
#include "cPhase.h"
#include "cBoard.h"

cPhase::cPhase()
    : myTable( (int)eAction::action_count, std::vector<ePhase>((int)ePhase::phase_count))
{
//          when                 while                          becomes
    Set( eAction::mill,       ePhase::placing,            ePhase::placing_removing  );
    Set( eAction::all_played, ePhase::placing,            ePhase::moving  );
    Set( eAction::remove,     ePhase::placing_removing,   ePhase::placing  );
    Set( eAction::move_src,   ePhase::moving,             ePhase::moving_destination );
    Set( eAction::mill,       ePhase::moving,             ePhase::moving_removing );
    Set( eAction::move_dst,   ePhase::moving_destination, ePhase::moving );
    Set( eAction::remove,     ePhase::moving_removing,    ePhase::moving );
    Set( eAction::move_src,   ePhase::lasker,             ePhase::lasker_destination );
    Set( eAction::mill,       ePhase::lasker,             ePhase::lasker_removing );
    Set( eAction::move_dst,   ePhase::lasker_destination, ePhase::lasker );
    Set( eAction::remove,     ePhase::lasker_removing,    ePhase::lasker );
}

void cPhase::Set( eAction A, ePhase current, ePhase next )
{
    myTable[ (int)A ][ (int)current ] = next;
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
    int prev = (int)myPhase;
    myPhase = myTable[ (int)A ][ prev ];
    std::cout << "Phase " << (int)A <<" "
              << prev <<" "<< (int)myPhase << "\n";

    if( myPhase == ePhase::none )
    {
        throw std::runtime_error("cPhase::Action error");
    }
}
//
//void cPhase::Action_old( eAction A )
//{
//    ePhase prev = myPhase;
//    myPhase = ePhase::none;
//    switch( prev )
//    {
//    case ePhase::placing:
//    {
//        switch( A )
//        {
//        case eAction::mill:
//            myPhase = ePhase::placing_removing;
//            break;
//        case eAction::all_played:
//            myPhase = ePhase::moving;
//            break;
//        }
//    }
//    break;
//
//    case ePhase::placing_removing:
//    {
//        switch( A )
//        {
//        case eAction::remove:
//            myPhase = ePhase::placing;
//            break;
//        }
//    }
//    break;
//
//    case ePhase::moving_removing:
//    {
//        switch( A )
//        {
//        case eAction::remove:
//            myPhase = ePhase::moving;
//            break;
//        }
//    }
//    break;
//
//    case ePhase::moving:
//    {
//        switch( A )
//        {
//        case eAction::move_src:
//            myPhase = ePhase::moving_destination;
//            break;
//        }
//    }
//    break;
//
//    case ePhase::moving_destination:
//    {
//        switch( A )
//        {
//        case eAction::move_dst:
//            myPhase = ePhase::moving;
//            break;
//        }
//    }
//    break;
//
//    case ePhase::lasker:
//    {
//        switch( A )
//        {
//        case eAction::move_dst:
//            myPhase = ePhase::lasker_destination;
//            break;
//        case eAction::mill:
//            myPhase = ePhase::lasker_removing;
//            break;
//        case eAction::all_played:
//            myPhase = ePhase::moving;
//            break;
//        }
//    }
//    break;
//
//    case ePhase::lasker_destination:
//    {
//        switch( A )
//        {
//        case eAction::move_dst:
//            myPhase = ePhase::lasker;
//            break;
//        }
//    }
//    break;
//
//    case ePhase::lasker_removing:
//    {
//        switch( A )
//        {
//        case eAction::remove:
//            myPhase = ePhase::lasker;
//            break;
//        }
//    }
//    break;
//    }
//
//    std::cout << "Phase " << (int)A <<" "
//              << (int)prev <<" "<< (int)myPhase << "\n";
//
//    if( myPhase == ePhase::none )
//    {
//        throw std::runtime_error("cPhase::Action error");
//    }
//}

