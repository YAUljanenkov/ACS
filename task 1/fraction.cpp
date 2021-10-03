#include "fraction.h"
#include "rnd.h"
#include <cstdio>

void In(fraction &r, FILE *in) {
    fscanf(in, "%d%d", &r.x, &r.y);
}

void InRnd(fraction &r) {
    r.x = Random();
    r.y = Random();
}

void Out(fraction &r, FILE *out) {
    fprintf(out, "%s", "It's a fraction: ");
    fprintf(out, "%d", r.x);
    fprintf(out, "%s", "/");
    fprintf(out, "%d", r.y);
    fprintf(out, "%s", ".");
    fprintf(out, "%s", " It's decimal value: ");
    fprintf(out, "%f", decimal(r));
    fprintf(out, "%s", "\n");
}

double decimal(fraction &r) {
    return static_cast<double>(r.x) / r.y;
}