#include <cstdio>
#include "container.h"
//#include "chrono"

int main(int argc, char *argv[]) {
//    typedef std::chrono::high_resolution_clock clock;
//    typedef std::chrono::duration<float, std::milli> duration;
//    static clock::time_point start = clock::now();
    if (argc != 3) {
        printf("%s%d%s", "Incorrect number of arguments: expected 2, got ", argc, ".\n");
        return 1;
    }

    container c;
    Init(c);
    auto inF = fopen(argv[1], "r");
    In(c, inF);
    fclose(inF);
    auto f = fopen(argv[2], "w");
    Out(c, f);
    StraightMerge(c, f);
    fclose(f);

    printf("Program has successfully finished working. \n");
//    duration elapsed = clock::now() - start;
//    printf("%f %s", elapsed.count(), "ms");
//    scanf("%s");
    return 0;
}
