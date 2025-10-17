//
// Created by kalio on 2025-10-17.
//

#ifndef LEARNC_HTTP_ERRORS_H
#define LEARNC_HTTP_ERRORS_H

typedef enum {
    HTTP_BAD_REQUEST = 400,
    HTTP_UNAUTHORIZED = 401,
    HTTP_FORBIDDEN = 403,
    HTTP_NOT_FOUND = 404,
    HTTP_METHOD_NOT_ALLOWED = 405,
    HTTP_TEAPOT = 418,
    HTTP_INTERNAL_SERVER_ERROR = 500,
}http_error_code_t;


char *httpErrorString(http_error_code_t code);

#endif //LEARNC_HTTP_ERRORS_H