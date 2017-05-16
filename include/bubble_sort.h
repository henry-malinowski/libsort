/**
 * @file
 * A C header file that includes a type agnostic bubble sort.
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

#ifndef SORT_BUBBLE_H
#define SORT_BUBBLE_H

/**
 * @brief Performs bubble sort on an arbitrarily typed array.
 * @details This specific implementation contains the trivial optimizations of
 *  checking if a swap has not occurred at the end of each outer-loop iteration,
 *  as well as decreasing the upper_bound of the outer loop each iteration.
 * @param base   [in,out] A pointer to the beginning of the array.
 * @param nmbers [in]     The number of items in the array.
 * @param size   [in]     The size of the individual elements of the array.
 * @param cmp    [in]     A comparator function for the sort. This function must
 *  return a negative integer if the first arg is "greater than" the second arg;
 *  this indicates a swap should occur. In other words this function follows
 *  qsort's comparator function pattern.
 *
 * <b>Example usage:</b>
 * @code{.c}
 *  bubble_sort(array, sizeof(array)/sizeof(array[0]), sizeof(array[0]), cmp_func);
 * @endcode
 * @see <a href="https://en.wikipedia.org/wiki/Bubble_sort">
 * Bubble sort | Wikipedia</a>
 * @copyright MIT License.
 */
void bubble_sort(void* base, size_t nmbers, size_t size, int (*cmp)(const void*, const void*));


#endif /* SORT_BUBBLE_H */
