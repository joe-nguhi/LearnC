//
// Created by kalio on 2025-10-24.
//

#include "generic_swap.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
// #include "bootlib.h"

void swap(void *a, void *b, size_t size) {
    void *buffer = malloc(size);
    memcpy(buffer, a, size);
    memcpy(a, b, size);
    memcpy(b, buffer, size);
    free(buffer);
}
