/**
 * A C source file that includes several type agnostic array
 *  partitioning schemas.
 *
 * @copyright (C) 2017 Henry Malinowski <malinowski.henry@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <malloc.h>
#include <assert.h>
#include <memory.h>
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


/**
 * @brief Copies (size) bytes from pointer b to pointer a.
 */
#define COPY(a, b, size)                \
    do                                  \
    {                                   \
        size_t __size = (size);         \
        char *__a = (a), *__b = (b);    \
        do                              \
        {                               \
            *__a++ = *__b++;            \
        } while (--__size > 0);         \
    } while (0)


int
partition_verify(const void* base, size_t nmbers, size_t size,
                     int (*cmp)(const void *, const void *), void* pivot)
{
    const char* i = (char*) base;
    const char* upper_limit = (char*) base + (nmbers * size);

    /* check value less than the pivot */
    while (i < (char*) pivot && i < upper_limit)
    {
        if (cmp(i, pivot) > 0)/* if true, a swap that needs to occur did not*/
            return 0;
        else
            i += size;
    }

    /* skip of the pivot */
    i += size;

    while (i < upper_limit) {
        if (cmp(i, pivot) <= 0)/* if true, a swap that needs to ocurr did not*/
            return 0;
        else
            i += size;
    }

    return 1;
}


void*
partition_lomuto(void *base, size_t nmbers, size_t size,
                       int (*cmp)(const void *, const void *))
{
    /*
     * i: track where the pivot will end up (a.k.a. index)
     * j: main iterator
     * pivot: set as the right most element
     */
    char* i = (char*) base;
    char* j = (char*) base;
    char* pivot = (char*)base + ((nmbers-1)*size);

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
    char* i = (char*) base;
    char* j = (char*) base + ((nmbers-1)*size);
    char* pivot = malloc(size);

    assert(pivot != NULL);
    //COPY(pivot, base, size);

    memcpy(pivot, base, size);

    /* Perform Hoare's partitioning until pointers i and j meet. */
    while (1) {
        /* Find the leftmost element "greater than" or equal to the pivot */
        while (cmp(i, pivot) < 0)
            i += size;

        /* Find the rightmost element "less than" or equal to the pivot */
        while (cmp(j, pivot) > 0)
            j -= size;


        if (i < j) SWAP(i, j, size);
        else break;
    }

    free(pivot);
    return j;
}


