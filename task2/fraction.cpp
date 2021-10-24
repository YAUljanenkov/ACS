#include "fraction.h"
#include "rnd.h"
#include <cstdio>

void fraction::In(FILE *in) {
    fscanf(in, "%d%d", &x, &y);
}

void fraction::InRnd() {
    x = Random();
    y = Random();
}

void fraction::Out(FILE *out) {
    fprintf(out, "%s", "It's a fraction: ");
    fprintf(out, "%d", x);
    fprintf(out, "%s", "/");
    fprintf(out, "%d", y);
    fprintf(out, "%s", ".");
    fprintf(out, "%s", " It's decimal value: ");
    fprintf(out, "%f", Decimal());
    fprintf(out, "%s", "\n");
}

double fraction::Decimal() {
    return static_cast<double>(x) / y;
}
