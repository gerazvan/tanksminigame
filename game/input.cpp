#include "input.h"
#include <conio.h>
using namespace std;

void input::init(){}
void input::close(){}

char input::getc()
{
    if(_kbhit())
    {
        char c=_getch();
        if(c==0)
            c=_getch();
        return c;
    }
    return 0;
}
