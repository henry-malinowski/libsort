/**
 * A C source file that includes a type agnostic heap sort.
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

#include "../include/heap_sort.h"

/**
 * @brief Macro that gives the left-child of a parent node.
 * @param i The an index in the array.
 */
#define L_CHILD(i) ((2*(i)) + 1)


/**
 * @brief Macro that gives the right-child of a parent node.
 * @param i The an index in the array.
 */
#define R_CHILD(i) ((2*(i)) + 2)


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
heap_sort(void* base, size_t nmemb, size_t size,
          int(*cmp)(const void*, const void*))
{
    /* first: A pointer to the first element in the array
     *  last: A pointer to the current last element in the array.
     */
    char* const first = (char*) base;
    char* last = first + (nmemb-1)*size;
    hs_build_heap(base, nmemb, size, cmp);

    /* - Swap the first and 'last' elements of the array.
     * - Decrease the the array bounds the 1 element.
     * - Fix the heap starting from the first element.
     */
    while (nmemb > 1)
    {
        SWAP(first, last, size);
        --nmemb;
        last -= size;

        hs_heapify(base, nmemb, size, cmp, 0);
    }
}


void
hs_build_heap(void* base, size_t nmemb, size_t size,
              int(*cmp)(const void*, const void*))
{
    size_t i;
    for (i = (nmemb-2)/2; i > 0; --i)
    {
        hs_heapify(base, nmemb, size, cmp, i);
    }
    hs_heapify(base, nmemb, size, cmp, 0);
}


void
hs_heapify(void* base, size_t nmemb, size_t size,
           int(*cmp)(const void*, const void*), size_t i_start)
{
    /* largest_idx: the index that largest_ptr points to
     * largest_ptr: a pointer to the element we are fixing from
     *    left_ptr: pointer to the left-child of i_start
     *   right_ptr: pointer to the right-child of i_start
     *       limit: a pointer past the end of the array (don't dereference)
     */
    size_t largest_idx = i_start;
    char* largest_ptr  = (char*) base + i_start * size;
    char* left_ptr     = (char*) base + L_CHILD(i_start) * size;
    char* right_ptr    = (char*) base + R_CHILD(i_start) * size;
    char* const limit  = (char*) base + (size * nmemb);

    /* If the left-child of i_start is valid AND
     *  it is greater than the i_start ...
     *   - reassign largest_* to be the left-child
     */
    if (left_ptr < limit && cmp(left_ptr, largest_ptr) > 0)
    {
        largest_ptr = left_ptr;
        largest_idx = L_CHILD(i_start);
    }

    /* If the right-child of i_start is valid AND
     *  it is greater than the largest_* found so far ...
     *   - reassign largest_* to be the right-child
     */
    if (right_ptr < limit && cmp(right_ptr, largest_ptr) > 0)
    {
        largest_ptr = right_ptr;
        largest_idx = R_CHILD(i_start);
    }

    /* If the largest index is no longer i_start...
     *  - swap the contents of the left or right child with i_start
     *  - recursively fix the heap down starting from the new largest index.
     */
    if (largest_idx != i_start)
    {
        SWAP(largest_ptr, (char*) base + i_start * size, size);
        hs_heapify(base, nmemb, size, cmp, largest_idx);
    }
}
