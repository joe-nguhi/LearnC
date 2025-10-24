//
// Created by kalio on 2025-10-24.
//

#include "../../munit/munit.h"
#include "../swap_integers.h"


MunitResult test_swap_ints(const MunitParameter params[], void *data) {
  (void) params;
  (void) data;

  int a = 5;
  int b = 6;

  swap_ints(&a, &b);

  munit_assert_int(a, ==, 6); // a is now 6
  munit_assert_int(b, ==, 5); // b is now 5
  return MUNIT_OK;
}

MunitResult test_swap_ints_same(const MunitParameter params[], void *data) {
  (void) params;
  (void) data;

  int a = 5;

  swap_ints(&a, &a);

  munit_assert_int(a, ==, 5); // a is still 5
  return MUNIT_OK;
}



static MunitTest tests[] = {
    {"test_swap_ints", test_swap_ints,},
    {"test_swap_ints_same", test_swap_ints_same,},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

MunitSuite swapIntegersSuite = {
    "/swap-integers/",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

