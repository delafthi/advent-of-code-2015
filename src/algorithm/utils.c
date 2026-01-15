#include "algorithm/utils.h"

void swap_int(int *value1, int *value2) {
    *value1 ^= *value2;
    *value2 ^= *value1;
    *value1 ^= *value2;
}
