#ifndef __complex__
#define __complex__

#include <cstdio>
#include "rnd.h"
#include "number.h"

class complex:public number {
private:
    int x, y;
public:
    void In(FILE *in) override;
    void InRnd();
    void Out(FILE *out) override;
    double Decimal() override;
};

#endif


