//
// Created by kalio on 2025-10-23.
//

#include "malloc.h"

#include <stdlib.h>

int *allocate_scalar_array(int size, int multiplier) {
    int *arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = i * multiplier;
    }
    return arr;
}
