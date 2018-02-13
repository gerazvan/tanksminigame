#ifndef OUTPUT_H
#define OUTPUT_H
#include "engine.h"
class output
{
    engine& motor;
public:
    output(engine&);
    void init();
    void close();
    void afisare();

};

#endif // OUTPUT_H

