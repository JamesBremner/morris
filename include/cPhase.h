#ifndef CPHASE_H
#define CPHASE_H


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
    };

    enum class eAction
    {
        mill,
        all_played,
        move_src,
        move_dst,
        remove,
        fail,
    };
    cPhase();

    void Clear();

    /** Change Phase in reponse to Action
        @param[in] A the Action

        Throws runtime exception if cannot handle change
    */
    void Action( eAction A );

    ePhase get()
    {
        return myPhase;
    }


protected:

private:
    ePhase myPhase;
};

#endif // CPHASE_H
