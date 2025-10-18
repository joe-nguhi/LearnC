//
// Created by kalio on 2025-10-18.
//

#ifndef LEARNC_SNEK_OBJECT_H
#define LEARNC_SNEK_OBJECT_H

typedef enum {INTEGER, STRING}snek_object_kind_t;

typedef union {
    int v_int;
    char *v_string;
}snek_object_data_t;

typedef struct {
    snek_object_kind_t kind;
    snek_object_data_t data;
}snek_object_t;

snek_object_t new_integer(int);
snek_object_t new_string(char *str);
void format_object (snek_object_t obj, char *buf);
#endif //LEARNC_SNEK_OBJECT_H