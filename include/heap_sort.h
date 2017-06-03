/**
 * @file
 * A C header file that includes a type agnostic heap sort.
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

#include <stddef.h>

#ifndef SORT_HEAP_H
#define SORT_HEAP_H

/**
 * @brief Performs heap sort on an arbitrarily typed array.
 * @param base  [in,out] A pointer to the beginning of the array.
 * @param nmemb [in]     The number of items in the array.
 * @param size  [in]     The size of the individual elements of the array.
 * @param cmp   [in]     A comparator function for the sort. This function must
 *  return a negative integer if the first arg is "greater than" the second arg;
 *  this indicates a swap should occur. In other words this function follows
 *  qsort's comparator function pattern.
 *
 * <b>Example usage:</b>
 * @code{.c}
 *  heap_sort(array, ARRAY_SIZE(array), sizeof(array[0]), cmp_func);
 * @endcode
 * @see <a href="https://en.wikipedia.org/wiki/Heapsort">
 * Heapsort | Wikipedia</a>
 * @copyright MIT License.
 */
void heap_sort(void* base, size_t nmemb, size_t size,
               int(*cmp)(const void*, const void*));


/**
 * @brief Takes an array and builds the array into a max heap.
 * @param base  [in,out] A pointer to the beginning of the array.
 * @param nmemb [in]     The number of items in the array.
 * @param size  [in]     The size of the individual elements of the array.
 * @param cmp   [in]     A comparator function for the sort. This function must
 *  return a negative integer if the first arg is "greater than" the second arg;
 *  this indicates a swap should occur. In other words this function follows
 *  qsort's comparator function pattern.
 *
 * <b>Example usage:</b>
 * @code{.c}
 *  hs_build_heap(array, ARRAY_SIZE(array), sizeof(array[0]), cmp_func);
 * @endcode
 * @see <a href="https://en.wikipedia.org/wiki/Heapsort">
 * Heapsort | Wikipedia</a>
 * @copyright MIT License.
 */
void hs_build_heap(void* base, size_t nmemb, size_t size,
                   int(*cmp)(const void*, const void*));


/**
 * @brief Restores the heap property for a rooted at element \p i_start.
 * @details The function assumes that all the children below \p i_start is a
 *  valid heap.
 * @param base  [in,out] A pointer to the beginning of the array.
 * @param nmemb [in]     The number of items in the array.
 * @param size  [in]     The size of the individual elements of the array.
 * @param cmp   [in]     A comparator function for the sort. This function must
 *  return a negative integer if the first arg is "greater than" the second arg;
 *  this indicates a swap should occur. In other words this function follows
 *  qsort's comparator function pattern.
 * @param i_start The index to start fixing the heap from.
 *
 * <b>Example usage:</b>
 * Fix the heap starting at the first element.
 * @code{.c}
 *  hs_build_heap(array, ARRAY_SIZE(array), sizeof(array[0]), cmp_func, 0);
 * @endcode
 * Fix the heap starting from the i,th element.
 * @code{.c}
 *  hs_build_heap(array, ARRAY_SIZE(array), sizeof(array[0]), cmp_func, i);
 * @endcode
 *
 */
void hs_heapify(void* base, size_t nmemb, size_t size,
                int(*cmp)(const void*, const void*), size_t i_start);

#endif /* SORT_HEAP_H */
