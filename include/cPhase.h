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
