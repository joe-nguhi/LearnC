//
// Created by kalio on 2025-10-24.
//

#include "swap_integers.h"

void swap_ints(int *a, int *b) {
    const int tempA = *a;
    *a = *b;
    *b = tempA;
}
