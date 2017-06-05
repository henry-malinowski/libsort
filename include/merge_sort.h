/**
 * @file
 * A C header file that includes a type agnostic merge sort.
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

#ifndef SORT_MERGE_H
#define SORT_MERGE_H

/**
 * @brief Performs merge sort on an arbitrarily typed array.
 * @details This specific implementation could be described as a merge sort that
 *  contains a single optimization; a single allocation is performed for the
 *  auxiliary array. However, since this is currently a "global variable", the
 *  current merge sort implementation can't trivially be made multi-thread/core.
 *  It also does not contain fallback sorting algorithms for certain cases or
 *  block merging.
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
 *  merge_sort(array, ARRAY_SIZE(array), sizeof(array[0]), cmp_func);
 * @endcode
 * @see <a href="https://en.wikipedia.org/wiki/Merge_sort">
 *  Merge Sort | Wikipedia</a>
 * @copyright MIT License.
 */
void merge_sort(void *base, size_t nmemb, size_t size,
                int(*cmp)(const void *, const void *));

/**
 * @brief Merges two portions of contiguous memory.
 * @details Merge, combines two contiguous portions of memory in order in
 *  accordance with the return value of \p cmp. The starting point of the
 *  contiguous memory is defined to the \p base. The first portion ends at...
 *  \code{.c}
 *      void* bound = base + (size * nmemb1);
 *  \endcode
 *  This is also beginning of the second portion of memory to merge. This second
 *  portion of memory is defined to end at...
 *  \code{.c}
 *      void* end = bound + (size * nmemb2);
 *  \endcode
 * If the sub-array aren't sorted, then the output in \p base will not sorted.
 * @param base [in,out] The beginning of the contiguous portion of memory to
 *  merge to and from. This must be valid allocated memory from \c base to
 *  \code{.c}
 *      base + size * (nmemb1 + nmemb2);
 *  \endcode If this is not valid, segmentation faults will occur.
 * @param nmemb1 [in] The number of elements in the first portion of memory.
 * @param nmemb2 [in] The number of elements in the second portion of memory.
 * @param size [in] The size of the individual elements of the array.
 * @param cmp [in] A comparator function for the sort. This function must
 *  return a negative integer if the first arg is "greater than" the second arg;
 *  this indicates a swap should occur. In other words this function follows
 *  qsort's comparator function pattern.
 * <b>Example usage:</b>
 * @code{.c}
 *  merge(array, 10, 10, sizeof(array[0]), cmp_func);
 * @endcode
 * @note If memory fails to be allocated in merge() the calling program will
 *  exit with code 2.
 * @see <a href="https://en.wikipedia.org/wiki/Merge_sort">
 *  Merge Sort | Wikipedia </a>
 * @copyright MIT License.
 */
void merge(void* base, size_t nmemb1, size_t nmemb2, size_t size,
           int(*cmp)(const void *, const void *));

#endif /* SORT_MERGE_H */
