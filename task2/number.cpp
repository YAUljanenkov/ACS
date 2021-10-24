
#include "number.h"
#include "complex.h"
#include "fraction.h"
#include "polar.h"
#include <cstdio>
#include <cstdlib>


number* number::GetNumber(FILE *in) {
    int k;
    fscanf(in, "%d", &k);
    number* nb;
    switch (k) {
        case 1:
            nb = new complex();
            break;
        case 2:
            nb = new fraction();
            break;
        case 3:
            nb = new polar();
            break;
        default:
            return nullptr;
    }
    nb->In(in);
    return nb;
}


number *number::GetRandomNumber() {
    number *nb;
    int k = rand() % 3 + 1;
    printf("%d", k);
    switch (k) {
        case 1:
            nb = new complex();
            break;
        case 2:
            nb = new fraction();
            break;
        case 3:
            nb = new polar();
            break;
        default:
            return nullptr;
            nb->GetRandomNumber();
    return nb;
    }
}


void number::Out(FILE *out) {
    printf("Incorrect figure!");
}

double number::Decimal() {
    return 0.0;
}

void number::In(FILE *in) {

}
