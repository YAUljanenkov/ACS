#ifndef __number__
#define __number__

#include <cstdio>

class number {
public:
    number* GetNumber(FILE *in);
    virtual void In(FILE *in);
    static number* GetRandomNumber();
    virtual void Out(FILE *out);
    virtual double Decimal();
};

#endif