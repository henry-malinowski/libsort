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


int
partition_verify(const void* base, size_t nmbers, size_t size,
                     int (*cmp)(const void *, const void *), void* pivot)
{
    register size_t i;
    register const void* upper_limit = base + (nmbers * size);

    /* check value less than the pivot */
    while (base < pivot && base < upper_limit)
    {
        if (cmp(base, pivot) > 0)/* if true, a swap that needs to occur did not*/
            return 0;
        else
            base += size;
    }

    /* skip of the pivot */
    base += size;

    while (base < upper_limit) {
        if (cmp(base, pivot) <= 0)/* if true, a swap that needs to ocurr did not*/
            return 0;
        else
            base += size;
    }

    return 1;
}


void*
partition_lomuto(void *base, size_t nmbers, size_t size,
                       int (*cmp)(const void *, const void *))
{
    void* i = base;              /* track where the pivot will end up "index" */
    void* j = base;                         /* main iterator                  */
    void* pivot = base + ((nmbers-1)*size); /* pivot is the right-most element*/


    /* perform Lomuto's partition up to the element right be fore the pivot */
    while (j < pivot)
    {
        if (cmp(j, pivot) <= 0)
        {
            SWAP(i, j, size);
            i += size;
        }

        j += size; /* increment j */
    }

    /* move the pivot to it's final location */
    SWAP(pivot, i, size);

    return i;
}


void*
partition_hoare(void *base, size_t nmbers, size_t size,
                int (*cmp)(const void *, const void *))
{
    void* pivot = base;           /* pivot is the left-most element           */
    void* i = base - size;        /* incremented before cmp (won't access oob)*/
    void* j = base+(nmbers*size); /* decremented before cmp (won't access oob)*/

    /* Perform Hoare's partitioning until pointers i and j meet. */
    while (i < j)
    {
        /* Find the leftmost element "greater than" or equal to the pivot */
        do
        {
            i += size;
        } while (cmp(i, pivot) < 0);

        /* Find the rightmost element "less than" or equal to the pivot */
        do
        {
            j -= size;
        } while (cmp(j, pivot) > 0);

        SWAP(i, j, size);
    }

    return j;
}


