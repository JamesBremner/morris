#ifndef CPHASE_H
#define CPHASE_H
#include <vector>

class cPhase
{
public:

    enum class ePhase
    {
        none,
        placing,
        placing_removing,
        moving,
        moving_destination,
        moving_removing,
        flying,
        lasker,
        lasker_destination,
        lasker_removing,
        phase_count
    };

    enum class eAction
    {
        mill,
        all_played,
        move_src,
        move_dst,
        remove,
        fail,
        action_count
    };
    cPhase();

    void Clear();

    /** Change Phase in reponse to Action
        @param[in] A the Action

        Throws runtime exception if cannot handle change
    */
    void Action( eAction A );
    void Action_old( eAction A );

    ePhase get()
    {
        return myPhase;
    }


protected:

private:
    ePhase myPhase;
    std::vector< std::vector< ePhase > > myTable;

    void Set( eAction A, ePhase current, ePhase next );
};

#endif // CPHASE_H
