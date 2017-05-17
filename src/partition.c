#include "../include/partition.h"

/**
 * @brief Byte-wise swap two items of size \p size.
 * This code is borrowed straight from the GCC qsort implementation of SWAP.
 */
#define SWAP(a, b, size)                \
    do                                  \
    {                                   \
        size_t __size = (size);			\
        char *__a = (a), *__b = (b);    \
        do                              \
        {                               \
            char __tmp = *__a;          \
            *__a++ = *__b;              \
            *__b++ = __tmp;             \
        } while (--__size > 0);         \
    } while (0)


void*
partition_lomuto(void *base, size_t nmbers, size_t size,
                       int (*cmp)(const void *, const void *))
{
    void* i = base; /* track where the pivot will end up "index" */
    void* j = base; /* main iterator */
    void* pivot = base + ((nmbers-1)*size); /* pivot is the right-most element*/
    //void* upper_limit = pivot - size;


    /* perform Lomuto's partition up to the element right be fore the pivot */
    while (j < pivot-size)
    {
        if (cmp(j, pivot) <= 0) {
            SWAP(i, j, size);
            i += size;
        }


        j += size; /* increment j */
    }

    //i += size;

    /* move the pivot to it's final location */
    SWAP(pivot, i, size);


    return i;
}