//
// Created by kalio on 2025-10-24.
//

#include "swap_strings.h"

void swap_strings(char **a, char **b) {
    char *tP = *a;
    *a = *b;
    *b = tP;
}