//
// Created by Ярослав Ульяненков on 02.10.2021.
//

#include "complex.h"
#include <cstdio>
#include <cmath>


void In(complex &r, FILE *in) {
    fscanf(in, "%d%d", &r.x, &r.y);
}

void InRnd(complex &r) {
    r.x = Random();
    r.y = Random();
}

void Out(complex &r, FILE *out) {
    fprintf(out, "%s", "It's a complex number: ");
    fprintf(out, "%d", r.x);
    fprintf(out, "%s", "+");
    fprintf(out, "%d", r.y);
    fprintf(out, "%s", "*i.");
    fprintf(out, "%s", " It's distance: ");
    fprintf(out, "%f", decimal(r));
    fprintf(out, "%s", "\n");
}

double decimal(complex &r) {
    return sqrt(r.x * r.x + r.y * r.y);
}