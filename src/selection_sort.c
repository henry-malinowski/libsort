/**
 * A C source file that includes a type agnostic selection sort.
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

#include "../include/selection_sort.h"

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
    } while (0)                         \


void
selection_sort(void* base, size_t nmbers, size_t size,
               int (*cmp)(const void*, const void*))
{
    /* - Initialize upper limit of the array
     * - Initialize tracking pointers for sorting
     *  + i: tracks the outer loop
     *  + j: tracks the inner loop for finding the min
     *  + min_ptr: the current minimum candidate
     */
    const char* upper_limit = (char*) base + (nmbers*size);
    char *i, *min_ptr, *j;

    for (i = base; i < (upper_limit - size); i += size)
    {
        /* min = A[i] */
        min_ptr = i;

        /* find the minimum element in the array */
        for (j = min_ptr + size; j < upper_limit; j += size)
        {
            /* if j < min_ptr */
            if ( cmp(j, min_ptr) < 0 )
            {
                min_ptr = j;
            }
        }

        /* swap if the min if it is different from j */
        if (min_ptr != i) {
            SWAP(min_ptr, i, size);
        }
    }
}