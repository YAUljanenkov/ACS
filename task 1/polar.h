#ifndef __polar__
#define __polar__


#include <cstdio>

struct polar {
    int x, y;
};

void In(polar &r, FILE *in);

void InRnd(polar &r);

void Out(polar &r, FILE *out);

double decimal(polar &r);

#endif


