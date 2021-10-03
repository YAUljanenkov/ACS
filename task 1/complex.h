#ifndef __complex__
#define __complex__

#include <cstdio>
#include "rnd.h"

struct complex {
    int x, y;
};

void In(complex &r, FILE *in);

void InRnd(complex &r);

void Out(complex &r, FILE *out);

double decimal(complex &r);

#endif


