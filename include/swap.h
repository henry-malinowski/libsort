#include <stddef.h>

#ifndef MEMORY_SWAP_H
#define MEMORY_SWAP_H

/* The inline keyword was not introduced until the C99 standard, as such,
 *  if compiling with an older version of C a function-like macro with the same
 *  "definition" will be integrated instead.
 */
#if __STDC_VERSION__ >= 199901L
#define swap (a, b, size, use_long)     \
    do                                  \
    {                                   \
        size_t __size = (size);         \
        char *__a = (a), *__b = (b);    \
        do                              \
        {                               \
            char __tmp = *__a;          \
            *__a++ = *__b;              \
            *__b++ = __tmp;             \
        } while (--__size > 0);         \
    } while (0)

#endif
//__inline__ void swap(void* a, void* b, size_t size, int use_long);
#endif /* MEMORY_SWAP_H */
