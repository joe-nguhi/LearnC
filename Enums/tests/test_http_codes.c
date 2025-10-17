//
// Created by kalio on 2025-10-17.
//

#include "../http_codes.h"
#include "../../munit/munit.h"


MunitResult test_switch_enum(const MunitParameter params[], void *data) {
    (void) params;
    (void) data;

    munit_assert_string_equal(httpErrorString(HTTP_BAD_REQUEST), "400 Bad Request");
    munit_assert_string_equal(httpErrorString(HTTP_UNAUTHORIZED), "401 Unauthorized");
    munit_assert_string_equal(httpErrorString(HTTP_NOT_FOUND), "404 Not Found");
    munit_assert_string_equal(httpErrorString(HTTP_TEAPOT), "418 I AM A TEAPOT!");
    munit_assert_string_equal(httpErrorString(HTTP_INTERNAL_SERVER_ERROR), "500 Internal Server Error");

    return MUNIT_OK;
}

MunitResult test_switch_enum_default(const MunitParameter params[], void *data) {
    (void) params;
    (void) data;

    munit_assert_string_equal(httpErrorString((http_error_code_t)999), "Unknown HTTP status code");

    return MUNIT_OK;
}

static MunitTest tests[] = {
    {"/switch_enum", test_switch_enum, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/switch_enum_default", test_switch_enum_default, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

MunitSuite httpCodesSuite = {
    "/switch",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};
