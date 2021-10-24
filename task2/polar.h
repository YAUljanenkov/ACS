#ifndef __polar__
#define __polar__


#include <cstdio>
#include "number.h"

class polar: public number {
private:
    int x, y;
public:
    void In(FILE *in) override;
    void InRnd();
    void Out(FILE *out) override;
    double Decimal() override;
};

#endif


