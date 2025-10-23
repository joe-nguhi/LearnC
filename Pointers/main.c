//
// Created by kalio on 2025-10-23.
//

#include <stdio.h>
#include "../munit/munit.h"


extern MunitSuite pointerSuite;

int main(int argc, char *argv[]) {
    MunitSuite allSuites[] = {
        pointerSuite,
    };

    MunitSuite rootSuite = {
        "/enums",
        NULL,
        allSuites,
        1,
        MUNIT_SUITE_OPTION_NONE
    };
    return munit_suite_main(&rootSuite, NULL, argc, argv);
}
