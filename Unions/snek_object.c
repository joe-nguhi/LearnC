//
// Created by kalio on 2025-10-18.
//

#include <stdio.h>
#include "snek_object.h"

void format_object(snek_object_t obj, char *buf) {
    switch (obj.kind) {
        case STRING:
            sprintf(buf, "string:%s", obj.data.v_string);
            break;
        case INTEGER:
            sprintf(buf, "int:%d", obj.data.v_int);
            break;
        default:break;
    }
}

snek_object_t new_integer(int v) {
    snek_object_t object = {.kind = INTEGER, .data.v_int = v};
    return object;
}

snek_object_t new_string(char *str) {
    snek_object_t object = {.kind = STRING, .data.v_string = str};
    return object;
}
