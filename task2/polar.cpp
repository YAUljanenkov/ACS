#include "rnd.h"
#include <cstdio>
#include "polar.h"

void polar::In(FILE *in) {
    fscanf(in, "%d%d", &x, &y);
}

void polar::InRnd() {
    x = Random();
    y = Random();
}

void polar::Out(FILE *out) {
    fprintf(out, "%s", "It's a polar number: r=");
    fprintf(out, "%d", x);
    fprintf(out, "%s", ", phi=");
    fprintf(out, "%d", y);
    fprintf(out, "%s", ".");
    fprintf(out, "%s", " It's distance: ");
    fprintf(out, "%f", Decimal());
    fprintf(out, "%s", "\n");
}

double polar::Decimal() {
    return y;
}
