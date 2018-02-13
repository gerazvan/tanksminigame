#ifndef ENGINE_H
#define ENGINE_H

#define MAXNL 600
#define MAXNC 600
#define MAXNU 300
#define MAXNM 100
extern int scoro,scorz;
class unit;

class engine
{
    friend class unit;
    unit* unittab[MAXNL][MAXNC];
    unit* unitvect[MAXNU];
    int nc,nl,nu;
public:
    void init(int, int);
    int getnl();
    int getnc();
    int getnu();
    bool validxy(int, int);
    bool validpoz(int);
    unit* getunitxy(int, int);
    unit* getunitpoz(int);
    void next();
};

class unit
{
    friend class engine;
public:

    static engine motor;
private:
    int alive;
    int x,y,poz;
    int message[MAXNM];
    int nm;

    void react();
protected:
    unit(int,int);
    virtual ~unit();
    void die();
    void move(int dx, int dy);
    void sendmes(int pm, unit& pu);
    virtual void action()=0;
    virtual void behaviour(int)=0;
public:
    int getx();
    int gety();
    virtual void* gettip()=0;
};

#endif // ENGINE_H
