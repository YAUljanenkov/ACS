#ifndef __container__
#define __container__



//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "number.h"

struct container {
    enum {
        max_len = 10000
    };
    int len;
    number *cont[max_len];
};

void Init(container &c);

void Clear(container &c);

void In(container &c, FILE *in);

void InRnd(container &c, int size);

void Out(container &c, FILE *out);

// Сортировка чисел с использованием StraightMerge
void StraightMerge(container &c, FILE *out);

#endif
