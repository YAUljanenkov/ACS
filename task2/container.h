#ifndef __container__
#define __container__



//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "number.h"

class container {
private:
    enum {
        max_len = 10000
    };
    int len;
    number *cont[max_len];

public:
    container();

    void Clear();

    void In(FILE *in);

    void InRnd(int size);

    void Out(FILE *out);

// Сортировка чисел с использованием StraightMerge
    void StraightMerge(FILE *out);
};

#endif
