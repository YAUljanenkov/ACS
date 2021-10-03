#ifndef __number__
#define __number__

#include "polar.h"
#include "fraction.h"
#include "complex.h"
#include <cstdio>

struct number {
    enum key {
        FRACTION, POLAR, COMPLEX
    };
    key k;
    union {
        fraction f;
        complex c;
        polar p;
    };
};

number *In(FILE *in);

number *InRnd();

void Out(number &s, FILE *out);

double Decimal(number &s);

#endif