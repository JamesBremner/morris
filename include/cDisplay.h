#ifndef CDISPLAY_H
#define CDISPLAY_H


class cDisplay
{
    public:
        cDisplay();
        virtual ~cDisplay();

    virtual void Update() = 0;
    virtual void Sleep( int msecs ) = 0;

    protected:

    private:
};

#endif // CDISPLAY_H
