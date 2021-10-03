
#include "number.h"
#include <cstdio>
#include <cstdlib>


number *In(FILE *in) {
    number *sp;
    int k;
    fscanf(in, "%d", &k);
    switch (k) {
        case 1:
            sp = new number;
            sp->k = number::COMPLEX;
            In(sp->c, in);
            return sp;
        case 2:
            sp = new number;
            sp->k = number::FRACTION;
            In(sp->f, in);
            return sp;
        case 3:
            sp = new number;
            sp->k = number::POLAR;
            In(sp->p, in);
            return sp;
        default:
            return 0;
    }
}


number *InRnd() {
    number *nb;
    int k = rand() % 3 + 1;
    printf("%d", k);
    switch (k) {
        case 1:
            nb = new number;
            nb->k = number::COMPLEX;
            InRnd(nb->c);
            return nb;
        case 2:
            nb = new number;
            nb->k = number::FRACTION;
            InRnd(nb->f);
            return nb;
        case 3:
            nb = new number;
            nb->k = number::POLAR;
            InRnd(nb->p);
            return nb;
        default:
            return 0;
    }
}


void Out(number &s, FILE *out) {
    switch (s.k) {
        case number::COMPLEX:
            Out(s.c, out);
            break;
        case number::FRACTION:
            Out(s.f, out);
            break;
        case number::POLAR:
            Out(s.p, out);
            break;
        default:
            printf("%s", "Incorrect figure!");
    }
}

double Decimal(number &s) {
    switch (s.k) {
        case number::COMPLEX:
            return decimal(s.c);
        case number::FRACTION:
            return decimal(s.f);
        case number::POLAR:
            return decimal(s.p);
        default:
            return 0.0;
    }
}
