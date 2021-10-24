#ifndef __fraction__
#define __fraction__


#include <cstdio>
#include "number.h"

class fraction: public number {
private:
    int x, y;
public:
    void In(FILE *in) override;
    void InRnd();
    void Out(FILE *out) override;
    double Decimal() override;
};

#endif

