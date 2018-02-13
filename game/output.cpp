#include "output.h"
#include <stdlib.h>
#include <iostream>
#include <windows.h>
using namespace std;

void curPos(int x, int y)
{
HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
csbiInfo.dwCursorPosition.X=y;
csbiInfo.dwCursorPosition.Y=x;
SetConsoleCursorPosition(hStdout, csbiInfo.dwCursorPosition);
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

static int pictvect[MAXNU][2],npict;

output::output(engine &pm):motor(pm)
{
}

void output::init()
{
    ::npict=0;
    unsigned char c=219,z=177;
    system("cls");
    int i,j;
    for(i=0;i<=motor.getnl()+1;i++)
    {

        for(j=0;j<=motor.getnc()+1;j++)
        if(i==0 || j==0 || i==motor.getnl()+1 || j==motor.getnc()+1)
        cout<<c;
    else
        cout<<" ";

        cout<<endl;

    }

    for(i=0;i<motor.getnu();i++)
        if( ((char*)(motor.getunitpoz(i)->gettip()))[0] == (char)z)
        {
            curPos(motor.getunitpoz(i)->getx(),motor.getunitpoz(i)->gety());
            cout<<z;
        }
    hidecursor();

    curPos(15,85);
    cout<<"Score";

    i=0;
    while(((char*)(motor.getunitpoz(i)->gettip()))[0] == (char)z)
        i++;
    curPos(16,85);
    cout<<((char*)(motor.getunitpoz(i)->gettip()))[0]<<":";

    i++;
    while(((char*)(motor.getunitpoz(i)->gettip()))[0] == (char)z)
        i++;
    curPos(17,85);
    cout<<((char*)(motor.getunitpoz(i)->gettip()))[0]<<":";

}

void output::close()
{
    system("cls");
}

void output::afisare()
{
    int i,mnpict=::npict;
    for(i=0; i<mnpict; i++)
    {
        if(::pictvect[i][0]&&::pictvect[i][1])
        {
            curPos(::pictvect[i][0],::pictvect[i][1]);
            cout<<" ";
        }

    }
    ::npict=0;
    for(i=0;i<motor.getnu();i++)
        if( ((char*)(motor.getunitpoz(i)->gettip()))[0] != (char)177)
    {
        curPos(motor.getunitpoz(i)->getx(),motor.getunitpoz(i)->gety());
        cout<<((char*)(motor.getunitpoz(i)->gettip()))[0];
        ::pictvect[::npict][0]=motor.getunitpoz(i)->getx();
        ::pictvect[::npict][1]=motor.getunitpoz(i)->gety();
        ::npict++;
    }


    curPos(16,88); cout<<::scorz;
    curPos(17,88); cout<<::scoro;

}

