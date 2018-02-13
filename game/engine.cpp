#include "engine.h"
#include <iostream>
using namespace std;

int scoro=0,scorz=0;

///Engine
void engine::init(int a, int b)
{
    nc=b;
    nl=a;
    int i,j;
    for(i=0;i<=nl;i++)
        for(j=0;j<=nc;j++)
        unittab[i][j]=0;
    nu=0;
}

int engine::getnl()
{
    return nl;
}

int engine::getnc()
{
    return nc;
}

int engine::getnu()
{
    return nu;
}

bool engine::validxy(int x, int y)
{
    if( (1 <= x && x <= nl) && (1 <= y && y <= nc) )
        return 1;
    return 0;
}

bool engine::validpoz(int a)
{
    if( 0<=a && a<nu )
        return 1;
    return 0;
}

unit* engine::getunitxy(int x, int y)
{
    if(unittab[x][y]) return unittab[x][y];
    return 0;
}

unit* engine::getunitpoz(int poz)
{
    return unitvect[poz];
}

void engine::next()
{
    int i,j;
    for(i=0;i<nu;i++)
        (*unitvect[i]).action();
    for(i=0;i<nu;i++)
        (*unitvect[i]).react();
    for(i=0;i<nu;i++)
    if(unitvect[i]->alive==0)
    {
        if(((char*)(unitvect[i]->gettip()))[0] !='.')
        {
           if(i == 0)
                ::scoro++;
           else
                ::scorz++;
           unittab[unitvect[i]->x][unitvect[i]->y]=0;
           unittab[1][1]=unitvect[i];
           unitvect[i]->x=1;
           unitvect[i]->y=1;
           unitvect[i]->alive=1;
        }
        else
        {
        unittab[unitvect[i]->x][unitvect[i]->y]=0;
        delete unitvect[i];
        unitvect[i]=unitvect[nu-1];
        unitvect[nu-1]=0;
        i--;
        nu--;
         }
    }
}




///Unit
engine unit::motor;

void unit::react()
{
    for(int i=0; i<nm; i++)
        if(alive)
            behaviour(message[i]);
    nm=0;
}

unit::~unit(){}

unit::unit(int a, int b)
{
    if( motor.nu < MAXNU && motor.unittab[a][b]==0 )

    {
      motor.unitvect[motor.nu]=this;
      motor.nu++;
      x=a;
      y=b;
      motor.unittab[x][y]=this;
      nm=0;
      alive=1;

    }
}

void unit::die()
{
    alive=0;
}

void unit::move(int dx, int dy)
{
    motor.unittab[x][y]=0;
    x+=dx;
    y+=dy;
    motor.unittab[x][y]=this;
}

void unit::sendmes(int pm, unit &pu)
{
    if(pu.nm<MAXNM)
    {
        pu.message[pu.nm++]=pm;
    }
}

int unit::getx()
{
    return x;
}

int unit::gety()
{
    return y;
}


