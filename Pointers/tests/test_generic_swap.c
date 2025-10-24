//
// Created by kalio on 2025-10-24.
//

//
// Created by kalio on 2025-10-24.
//

#include "../../munit/munit.h"
#include "../generic_swap.h"


typedef struct CoffeeShop {
    uint64_t quality;
    uint64_t taste;
    uint64_t branding;
} coffee_shop_t;


MunitResult test_generic_ints(const MunitParameter params[], void *data) {
    (void) params;
    (void) data;

    int i1 = 1234;
    int i2 = 5678;

    swap(&i1, &i2, sizeof(int));
    munit_assert_int(i1, ==, 5678); //i1 should be i2's original value
    munit_assert_int(i2, ==, 1234); //i2 should be i1's original value
    // munit_assert_true(boot_all_freed());

    return MUNIT_OK;
}

MunitResult test_generic_strings(const MunitParameter params[], void *data) {
    (void) params;
    (void) data;

    char *s1 = "dax";
    char *s2 = "adam";

    swap(&s1, &s2, sizeof(char *));
    munit_assert_string_equal(s1, "adam"); //s1 should be s2's original value
    munit_assert_string_equal(s2, "dax"); //s2 should be s1's original value}
    // munit_assert_true(boot_all_freed());
    return MUNIT_OK;
}

MunitResult test_generic_structs(const MunitParameter params[], void *data) {
    (void) params;
    (void) data;

    coffee_shop_t sbucks = {2, 3, 4};
    coffee_shop_t terminalshop = {10, 10, 10};

    swap(&sbucks, &terminalshop, sizeof(coffee_shop_t));
    munit_assert_int(sbucks.quality, ==, 10); // sbucks.quality should be terminalshop.quality
    munit_assert_int(sbucks.taste, ==, 10); //  sbucks.taste should be terminalshop.taste
    munit_assert_int(sbucks.branding, ==, 10); //  sbucks.branding should be terminalshop.branding
    munit_assert_int(terminalshop.quality, ==, 2); //  terminalshop.quality should be sbucks.quality
    munit_assert_int(terminalshop.taste, ==, 3); //  terminalshop.taste should be sbucks.taste
    munit_assert_int(terminalshop.branding, ==, 4); //  terminalshop.branding should be sbucks.branding

    return MUNIT_OK;
}


static MunitTest tests[] = {
    {"test_generic_ints", test_generic_ints,},
    {"test_generic_strings", test_generic_strings,},
    {"test_generic_structs", test_generic_structs,},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

MunitSuite swapGenericsSuite = {
    "/swap-generics/",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};
