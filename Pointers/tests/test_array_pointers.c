#include "../../munit/munit.h"
#include "../array_pointers.h"
#include <stdlib.h>
#include <string.h>


MunitResult test_create_token_pointer_array_single(const MunitParameter params[], void *data) {
    (void) params;
    (void) data;

    token_t token = {"hello", 1, 1};
    token_t **result = create_token_pointer_array(&token, 1);


    // munit_assert_not_null(result); // Result array should not be null
    if (result == NULL) {
        munit_error("Result array should not be null\n");
    }
    munit_assert_not_null(result[0]); // First token pointer should not be null
    munit_assert_string_equal(result[0]->literal, "hello"); //Literal should match
    munit_assert_int(result[0]->line, ==, 1); //Line number should match
    munit_assert_int(result[0]->column, ==, 1); //Column number should match
    // munit_assert_ptr_not_equal(result[0], &token); //Token pointer should not point to original token

    if (result[0] == &token) {
        munit_error("Token pointer should not point to original token\n");
    }

    free(result[0]);
    free(result);

    return MUNIT_OK;
}

MunitResult test_create_token_pointer_array_multiple(const MunitParameter params[], void *data) {
    (void) params;
    (void) data;

    token_t tokens[3] = {
        {"foo", 1, 1},
        {"bar", 2, 5},
        {"baz", 3, 10}
    };
    token_t **result = create_token_pointer_array(tokens, 3);

    munit_assert_not_null(result); //Result array should not be null
    for (int i = 0; i < 3; i++) {
        munit_assert_not_null(result[i]); // Token pointer should not be null
        munit_assert_string_equal(result[i]->literal, tokens[i].literal); //Literal should match
        munit_assert_int(result[i]->line, ==, tokens[i].line); // Line number should match
        munit_assert_int(result[i]->column, ==, tokens[i].column); // Column number should match
        munit_assert_ptr_not_equal(result[i], &tokens[i]); // Token pointer should not point to original token
    }

    for (int i = 0; i < 3; i++) {
        free(result[i]);
    }

    free(result);

    return MUNIT_OK;
}

MunitResult test_create_token_pointer_array_memory_allocation(const MunitParameter params[], void *data) {
    (void) params;
    (void) data;

    token_t tokens[2] = {
        {"test1", 1, 1},
        {"test2", 2, 2}
    };
    token_t **result = create_token_pointer_array(tokens, 2);

    munit_assert_not_null(result); //Result array should not be null
    munit_assert_not_null(result[0]); //First token pointer should not be null
    munit_assert_not_null(result[1]); //Second token pointer should not be null
    munit_assert_ptr_not_equal(result[0], result[1]); // Token pointers should be different
    munit_assert_ptr_not_equal(result[0], &tokens[0]); //First token pointer should not point to original token
    munit_assert_ptr_not_equal(result[1], &tokens[1]); //Second token pointer should not point to original token

    free(result[0]);
    free(result[1]);
    free(result);

    return MUNIT_OK;
}


static MunitTest tests[] = {
    {"test_create_token_pointer_array_single", test_create_token_pointer_array_single},
    {"test_create_token_pointer_array_multiple", test_create_token_pointer_array_multiple},
    {"test_create_token_pointer_array_memory_allocation", test_create_token_pointer_array_memory_allocation},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

MunitSuite arrayPointerSuite = {
    "/array-pointers/",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};
