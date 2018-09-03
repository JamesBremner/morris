#ifndef CPLAYER_H
#define CPLAYER_H


class cPlayer
{
    public:
        cPlayer();
        virtual ~cPlayer();

        /** Play a piece
            @return true if pieces remain to be played
        */
        bool Piece();

        void Clear()
        {
            myPieces = 9;
        }

    protected:

    private:
        int myPieces;
};

#endif // CPLAYER_H
