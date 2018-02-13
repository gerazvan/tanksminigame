#include "joctanc.h"
using namespace std;

///Zid
unsigned char zid::nume=177;

zid::zid(int x, int y):unit(x,y)
{
}

void zid::action(){}
void zid::behaviour(int){}

void* zid::gettip()
{
    return &nume;
}


///Bomba
unsigned char bomba::nume='.';

void bomba::action()
{
    int xn,yn;
    xn=getx()+dirx;
    yn=gety()+diry;
    if(motor.validxy(xn,yn))
    {
        if(motor.getunitxy(xn,yn)==0)
        move(dirx,diry);
        else
        {
            sendmes(1,*(motor.getunitxy(xn,yn)));
            die();
        }
    }
    else
        die();
}

void bomba::behaviour(int a)
{
    if(a==1)
        die();
}

bomba::bomba(int x, int y, int ax, int by):unit(x,y)
{
    dirx=ax;
    diry=by;
}

void* bomba::gettip()
{
    return &nume;
}


///Tanc

char tanc::cc=0;


void tanc::action()
{
    if(cc==st)
        if(motor.validxy(getx(),gety()-1)&&motor.getunitxy(getx(), gety()-1)==0)
            {
                move(0,-1);
                pc=cc;
            }
    if(cc==sus)
        if(motor.validxy(getx()-1,gety())&&motor.getunitxy(getx()-1, gety())==0)
            {
                move(-1,0);
                pc=cc;
            }
    if(cc==dr)
        if(motor.validxy(getx(),gety()+1)&&motor.getunitxy(getx(), gety()+1)==0)
            {
                move(0,1);
                pc=cc;
            }
    if(cc==jos)
        if(motor.validxy(getx()+1,gety())&&motor.getunitxy(getx()+1, gety())==0)
            {
                move(1,0);
                pc=cc;
            }
    if(cc==foc)
    {
        if(pc==st && motor.validxy(getx(),gety()-1))
        {
                if(motor.getunitxy(getx(), gety()-1)==0)
                    new bomba(getx(),gety()-1,0,-1);

                else
                    sendmes(1, *(motor.getunitxy(getx(), gety()-1)));
        }
        if(pc==sus&& motor.validxy(getx()-1,gety()))
        {
                if(motor.getunitxy(getx()-1, gety())==0)
                    new bomba(getx()-1,gety(),-1,0);
                else
                    sendmes(1, *(motor.getunitxy(getx()-1, gety())));
        }
        if(pc==dr && motor.validxy(getx(),gety()+1))
        {
                if(motor.getunitxy(getx(), gety()+1)==0)
                    new bomba(getx(),gety()+1,0,1);
                else
                    sendmes(1, *(motor.getunitxy(getx(),gety()+1)));
        }
        if(pc==jos && motor.validxy(getx()+1,gety()))
        {
                if(motor.getunitxy(getx()+1, gety())==0)
                    new bomba(getx()+1,gety(),1,0);
                else
                    sendmes(1, *(motor.getunitxy(getx()+1,gety())));
        }
    }
}



void tanc::behaviour(int a)
{
    if(a==1)
        die();
}

tanc::tanc(char name, char l, char up, char r, char down, char fire, int x, int y):unit(x,y)
{
    nume=name;
    st=l;
    sus=up;
    dr=r;
    jos=down;
    foc=fire;
}

void* tanc::gettip()
{
    return &nume;
}


