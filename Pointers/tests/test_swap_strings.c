//
// Created by kalio on 2025-10-24.
//

#include "../../munit/munit.h"
#include "../swap_strings.h"


MunitResult test_swap_str(const MunitParameter params[], void *data) {
    (void) params;
    (void) data;

    char *a = "Hello";
    char *b = "Goodbye";

    swap_strings(&a, &b);

    munit_assert_string_equal(a, "Goodbye"); //a is now 'Goodbye'
    munit_assert_string_equal(b, "Hello"); // b is now 'Hello'
    return MUNIT_OK;
}

MunitResult test_swap_str_long(const MunitParameter params[], void *data) {
    (void) params;
    (void) data;

    char *a = "terminal.shop";
    char *b = "ssh";

    swap_strings(&a, &b);

    munit_assert_string_equal(a, "ssh"); //a is now 'ssh'
    munit_assert_string_equal(b, "terminal.shop"); // b is now 'terminal.shop'

    return MUNIT_OK;
}


static MunitTest tests[] = {
    {"test_swap_str", test_swap_str,},
    {"test_swap_str_long", test_swap_str_long,},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

MunitSuite swapStringsSuite = {
    "/swap-strings/",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};
