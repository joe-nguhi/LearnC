#include "../../munit/munit.h"
#include "../malloc.h"

/*
munit_case(RUN, test_allocate_scalar_array_size, {
  int size = 5;
  int multiplier = 2;
  int *result = allocate_scalar_array(size, multiplier);
  munit_assert_not_null(result, "Function should return a non-null pointer");
  free(result);
});

munit_case(RUN, test_allocate_scalar_array_values, {
  int size = 5;
  int multiplier = 2;
  int *result = allocate_scalar_array(size, multiplier);
  int expected[5];
  expected[0] = 0;
  expected[1] = 2;
  expected[2] = 4;
  expected[3] = 6;
  expected[4] = 8;
  for (int i = 0; i < size; i++) {
    munit_assert_int(result[i], ==, expected[i], "Element does not match expected value");
  }
  free(result);
});

munit_case(SUBMIT, test_allocate_scalar_array_zero_multiplier, {
  int size = 3;
  int multiplier = 0;
  int *result = allocate_scalar_array(size, multiplier);
  for (int i = 0; i < size; i++) {
    munit_assert_int(result[i], ==, 0, "All elements should be 0 with multiplier 0");
  }
  free(result);
});

munit_case(SUBMIT, test_allocate_too_much, {
  int size = 1024 * 1024 * 100;
  int multiplier = 1;
  int *result = allocate_scalar_array(size, multiplier);
  munit_assert_null(result, "Giant allocation should result in NULL");
});

 */

MunitResult test_allocate_scalar_array_size(const MunitParameter params[], void *data) {
    (void) params;
    (void) data;

    int size = 5;
    int multiplier = 2;
    int *result = allocate_scalar_array(size, multiplier);
    munit_assert_not_null(result);
    free(result);
    return MUNIT_OK;
}

MunitResult test_allocate_scalar_array_values(const MunitParameter params[], void *data) {
  (void) params;
  (void) data;

  int size = 5;
  int multiplier = 2;
  int *result = allocate_scalar_array(size, multiplier);
  int expected[5];
  expected[0] = 0;
  expected[1] = 2;
  expected[2] = 4;
  expected[3] = 6;
  expected[4] = 8;

  for (int i = 0; i < size; i++) {
    munit_assert_int(result[i], ==, expected[i]);
  }
  free(result);

  return MUNIT_OK;
}

MunitResult test_allocate_scalar_array_zero_multiplier(const MunitParameter params[], void *data) {
  (void) params;
  (void) data;

  int size = 3;
  int multiplier = 0;
  int *result = allocate_scalar_array(size, multiplier);

  for (int i = 0; i < size; i++) {
    munit_assert_int(result[i], ==, 0);
  }
  free(result);

  return MUNIT_OK;
}

MunitResult test_allocate_too_much(const MunitParameter params[], void *data) {
  (void) params;
  (void) data;

  // int size = 1024 * 1024 * 100;
  size_t impossible_size = SIZE_MAX;
  int multiplier = 1;
  int *result = allocate_scalar_array(impossible_size, multiplier);

  if (result != NULL) {
    free(result);
    munit_error("Giant allocation should result in NULL");
  }

  munit_assert_null(result);

  return MUNIT_OK;
}

static MunitTest tests[] = {
    {"test_allocate_scalar_array_size", test_allocate_scalar_array_size},
    {"test_allocate_scalar_array_values", test_allocate_scalar_array_values},
    {"test_allocate_scalar_array_zero_multiplier", test_allocate_scalar_array_zero_multiplier},
    {"test_allocate_too_much", test_allocate_too_much},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

MunitSuite mallocSuite = {
    "/malloc",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};
