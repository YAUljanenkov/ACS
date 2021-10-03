#ifndef __fraction__
#define __fraction__


#include <cstdio>

struct fraction {
    int x, y;
};

void In(fraction &r, FILE *in);

void InRnd(fraction &r);

void Out(fraction &r, FILE *out);

double decimal(fraction &r);

#endif

