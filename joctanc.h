
#ifndef JOCTANC_H
#define JOCTANC_H
#include "engine.h"
class zid: public unit
{
    static unsigned char nume;
protected:
    void action();
    void behaviour(int);
public:
    zid(int, int);
    void* gettip();
};


class bomba: public unit
{
    static unsigned char nume;
    int dirx,diry;
protected:
    void action();
    void behaviour(int);
public:
    bomba(int, int, int, int);
    void* gettip();
};

class tanc: public unit
{
public:
    static char cc;
private:
    unsigned char nume;
    char st,dr,sus,jos,foc;
    char pc;
protected:
    void action();
    void behaviour(int);
public:
    tanc(char,char,char,char,char,char,int,int);
    void* gettip();
};


#endif // JOCTANC_H
