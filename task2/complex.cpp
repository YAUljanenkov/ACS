//
// Created by Ярослав Ульяненков on 02.10.2021.
//

#include "complex.h"
#include <cstdio>
#include <cmath>


void complex::In(FILE *in) {
    fscanf(in, "%d%d", &x, &y);
}

void complex::InRnd() {
    x = Random();
    y = Random();
}

void complex::Out(FILE *out) {
    fprintf(out, "%s %d %s %d%s %s %f%s", "It's a complex number:", x, "+", y, "*i.", "It's distance:", Decimal(), "\n");
}

double complex::Decimal() {
    return hypot(x, y);
}