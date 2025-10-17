//
// Created by kalio on 2025-10-15.
//
#include "../munit/munit.h"


extern MunitSuite colorSuite;
extern MunitSuite httpCodesSuite;

int main(int argc, char *argv[]) {
    MunitSuite allSuites[] = {
        colorSuite,
        httpCodesSuite,
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
