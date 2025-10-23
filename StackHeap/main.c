//
// Created by kalio on 2025-10-23.
//

#include <stdio.h>
#include "../munit/munit.h"
#include "example.c"

extern MunitSuite mallocSuite;

int main(int argc, char *argv[]) {
    MunitSuite allSuites[] = {
        mallocSuite,
    };

    MunitSuite rootSuite = {
        "/enums",
        NULL,
        allSuites,
        1,
        MUNIT_SUITE_OPTION_NONE
    };
    return munit_suite_main(&rootSuite, NULL, argc, argv);

    /*coord_t *c1 = new_coord(10, 20);
    coord_t *c2 = new_coord(30, 40);
    coord_t *c3 = new_coord(50, 60);

    printf("c1: %d, %d\n", c1->x, c1->y);
    printf("c2: %d, %d\n", c2->x, c2->y);
    printf("c3: %d, %d\n", c3->x, c3->y);

    free(c1);
    free(c2);
    free(c3);*/
}
