/**
 * A C source file that includes a type agnostic quick sort.
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

#include "../include/quick_sort.h"
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
    } while (0)                         \


void
quick_sort(void* base, size_t nmbers, size_t size,
                    int (*cmp)(const void*, const void*))
{
    void* pivot;        /* the return value from the partition function    */
    size_t pivot_index; /* the intermediate value for finding upper-bounds */

    /* Reaching 1 element is the base case */
    if (nmbers <= 1) return;

    /* - partition the array
     * - the the memory address of the partition to calculate the index of the
     *   partition in array.
     * - This becomes the upper limit of the first recursive quick_sort call.
     * - The the pivot index subtracted from the nmbers with (1 removed to
     *   exclude the pivot itself from the count), is the nmbers in the second
     *   recursive call.
     */
    pivot = partition_lomuto(base, nmbers, size, cmp);
    pivot_index = (pivot - base)/size;

    /* Make the recursive calls */
    quick_sort(base, pivot_index, size, cmp);
    quick_sort(pivot+size, (nmbers-pivot_index)-1, size, cmp);
}
