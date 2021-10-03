#ifndef __rnd__
#define __rnd__

#include <cstdlib>

inline auto Random() {
    return rand() % 20 + 1;
}

#endif
