//
// Created by kalio on 2025-10-24.
//

#include "void_pointers.h"

void snek_zero_out(void *ptr, snek_object_kind_t kind){
    switch (kind) {
        case INTEGER:
           ((struct SnekInt*)ptr)->value = 0;
            break;
        case FLOAT:
            ((struct SnekFloat*)ptr)->value = 0.0;
            break;
        case BOOL:
            ((struct SnekBool*)ptr)->value = 0;
            break;
    }
}
