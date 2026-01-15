#include "algorithm/sort.h"

#include <stddef.h>
#include <stdio.h>

#include "utils.h"

void bubble_sort_int(int *values, size_t count) {
    if (count <= 1) {
        return;
    }

    for (size_t top = count - 1; top > 0; top--) {
        for (size_t i = 0; i < top; i++) {
            if (values[i] > values[i + 1]) {
                swap(values[i], values[i + 1]);
            }
        }
    }
}
