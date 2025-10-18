//
// Created by kalio on 2025-10-18.
//

#include "../munit/munit.h"

extern MunitSuite snekObjectSuite;

int main(int argc, char *argv[]) {
    MunitSuite allSuites[] = {
        snekObjectSuite,
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