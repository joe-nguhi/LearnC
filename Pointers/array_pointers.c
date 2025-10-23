#include "array_pointers.h"

#include <stdlib.h>
#include <string.h>


token_t** create_token_pointer_array(token_t* tokens, size_t count) {
    token_t** token_pointers = malloc(count * sizeof(token_t*));

    for (int i= 0; i < (int)count; i++) {
        token_t* tokenP = malloc(sizeof(token_t));
        *tokenP = tokens[i];
        // memcpy(tokenP, &tokens[i], sizeof(token_t));
        token_pointers[i] = tokenP;
    }

    return  token_pointers;
}
