//
// Created by kalio on 2025-10-23.
//

#include <stdio.h>
#include "../munit/munit.h"


extern MunitSuite arrayPointerSuite;
extern MunitSuite voidPointerSuite;
extern MunitSuite swapIntegersSuite;
extern MunitSuite swapStringsSuite;

int main(int argc, char *argv[]) {
    MunitSuite allSuites[] = {
        arrayPointerSuite,
        voidPointerSuite,
        swapIntegersSuite,
        swapStringsSuite,
    };

    MunitSuite rootSuite = {
        "/pointers",
        NULL,
        allSuites,
        1,
        MUNIT_SUITE_OPTION_NONE
    };
    return munit_suite_main(&rootSuite, NULL, argc, argv);
}
