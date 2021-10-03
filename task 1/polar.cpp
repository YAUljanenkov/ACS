#include "polar.h"
#include "rnd.h"
#include <cstdio>


void In(polar &r, FILE *in) {
    fscanf(in, "%d%d", &r.x, &r.y);
}

void InRnd(polar &r) {
    r.x = Random();
    r.y = Random();
}

void Out(polar &r, FILE *out) {
    fprintf(out, "%s", "It's a polar number: r=");
    fprintf(out, "%d", r.x);
    fprintf(out, "%s", ", phi=");
    fprintf(out, "%d", r.y);
    fprintf(out, "%s", ".");
    fprintf(out, "%s", " It's distance: ");
    fprintf(out, "%f", decimal(r));
    fprintf(out, "%s", "\n");
}

double decimal(polar &r) {
    return r.y;
}