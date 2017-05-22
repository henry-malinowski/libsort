/**
 * @file
 * A C header file that includes the definition for a type agnostic shell sort.
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

#ifndef SHELL_SORT_H
#define SHELL_SORT_H

/**
 * @brief Performs shell sort on an arbitrarily typed array.
 * @details The gap sequence for this function is statically stored in
 *  ../src/shell_sort.c. Currently it is using the Ciura's sequence.
 *  This can ne mathematically extended from existing elements by applying the
 *  recursive formula, \f$ h_k = \lfloor 2.25 h_{k-1} \rfloor \f$.
 *
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
 *  shell_sort(array, ARRAY_SIZE(array), sizeof(array[0]), cmp_func);
 * @endcode
 * @see <a href="https://en.wikipedia.org/wiki/Shellsort">
 *  Shell sort | Wikipedia</a>
 * @see <a href="https://oeis.org/A102549">
 * OEIS sequence A102549 | Optimal (best known) sequence of increment for shell
 * sort algorithm.</a>
 * @copyright MIT License.
 */
void shell_sort(void* base, size_t nmemb, size_t size, int (*cmp)(const void*, const void*));

#endif /* SHELL_SORT_H */
