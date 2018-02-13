#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

#include "output.h"
#include "joctanc.h"
#include "input.h"
#include "board.h"

void readControls()
{
    int x,y,ok=0;
    char name,l,up,r,d,fire;
    cout<<"Tank controls:"<<endl;
    cout<<"Name Left Up Right Down Fire"<<endl;
    cin>>name>>l>>up>>r>>d;
    cin.ignore();
    cin.get(fire);
    cout<<"Spawn coordinates"<<endl;
    cin>>x>>y;
    new tanc(name,l,up,r,d,fire,x,y);
    cout<<endl<<endl;
}

int main()
{
    input in;
    output out(tanc::motor);
    tanc::motor.init(25,78);

    cout<<"Tank 1:"<<endl;
    readControls();
    cout<<"Tank 2:"<<endl;
    readControls();

    boardWalls();

    in.init();
    out.init();
    out.afisare();
    do
    {
        tanc::cc=in.getc();
        tanc::motor.next();
        out.afisare();
        Sleep(25);
    }
    while(tanc::cc!=27);

    in.close();
    out.close();
    return 0;
}
