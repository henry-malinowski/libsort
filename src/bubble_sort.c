/**
 * A C source file that includes a type agnostic bubble sort.
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

#include "../include/bubble_sort.h"

/**
 * @brief Byte-wise swap two items of size \p size.
 * This code is borrowed straight from the GCC qsort implementation of SWAP.
 */
#define SWAP(a, b, size)                \
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


void
bubble_sort(void* base, size_t nmbers, size_t size,
            int (*cmp)(const void*, const void*))
{
    /* swap_occurred: sorting stops when this is set to zero for a whole cycle
     * upper_bound: tracks the upper boundary
     * i: iterates the main pointer
     */
    int swap_occurred = 1;
    char* upper_bound = (char*) base + (size * (nmbers));
    char* i;

    while (swap_occurred != 0 && (char*) base < upper_bound)
    {
        /* If this statement is still true at the end of this loop
         * then exit the loop (the list is in order.
         */
        swap_occurred = 0;

        /* For each element in the array, compare and swap if the current
         * element is greater than the element above it.
         */
        for (i = (char*) base; i < upper_bound-size; i += size)
        {
            if (cmp(i+size, i) < 0)
            {
                SWAP(i+size, i, size);
                swap_occurred = 1;
            }
        }

        /* The largest element in the array is always guaranteed to be
         * placed at the top of the array after a single pass so move
         * the outer boundary down by a single element
         */
        upper_bound -= size;
    }
}