//
// Created by kalio on 2025-10-23.
//
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} coord_t;

coord_t *new_coord(int x, int y) {
    coord_t *c = malloc(sizeof(coord_t));
    c->x = x;
    c->y = y;
    return c;
}
