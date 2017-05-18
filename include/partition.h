/**
 * @file
 * A C header file that includes function definitions for several type agnostic
 *  array partitioning schemas.
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

#ifndef SORTING_PARTITION
#define SORTING_PARTITION


int partition_verify(const void* base, size_t nmbers, size_t size,
                     int (*cmp)(const void *, const void *), void* pivot);

/**
 * @brief Partitions are array and returns a pointer to the pivot.
 * @details An input array \p base of length \p nmbers is partitioned in
 *  accordance with the return value of \p cmp. This partition algorithm uses
 *  Lomuto's partition scheme. This also means that the right-most element is
 *  the pivot.
 * @param base   [in,out] A pointer to the beginning of the array.
 * @param nmbers [in]     The number of items in the array.
 * @param size   [in]     The size of the individual elements of the array.
 * @param cmp    [in]     A comparator function for the sort. This function must
 *  return a integer less than or equal to zero if the first arg is "greater
 *  than or equal" the second arg; this indicates a swap should occur. In other
 *  words this function follows qsort's comparator function pattern.
 * @return A void pointer to the location of the partition.
 *
 * <b>Example usage:</b>
 * @code{.c}
 *  void* pivot = partition_lomuto(array, ARRAY_SIZE(array), sizeof(array[0]), cmp_func);
 * @endcode
 * @see <a href="https://en.wikipedia.org/wiki/Quicksort#Lomuto_partition_scheme">
 * Lomuto partition scheme (Quicksort) | Wikipedia</a>
 * @see <a href="http://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/">
 * Hoare’s vs Lomuto partition scheme in QuickSort | GeeksforGeeks </a>
 */
void* partition_lomuto(void* base, size_t nmbers, size_t size,
                       int (*cmp)(const void *, const void *));


/**
 * @brief Partitions are array and returns a pointer to the pivot.
 * @details An input array \p base of length \p nmbers is partitioned in
 *  accordance with the return value of \p cmp. This partition algorithm uses
 *  Hoare's partition scheme. This also means that the left-most element is the
 *  pivot.
 * @param base   [in,out] A pointer to the beginning of the array.
 * @param nmbers [in]     The number of items in the array.
 * @param size   [in]     The size of the individual elements of the array.
 * @param cmp    [in]     A comparator function for the sort. This function must
 *  return a integer less than or equal to zero if the first arg is "greater
 *  than or equal" the second arg; this indicates a swap should occur. In other
 *  words this function follows qsort's comparator function pattern.
 * @return A void pointer to the location of the partition.
 *
 * <b>Example usage:</b>
 * @code{.c}
 *  void* pivot = partition_hoare(array, ARRAY_SIZE(array), sizeof(array[0]), cmp_func);
 * @endcode
 * @see <a href="https://en.wikipedia.org/wiki/Quicksort#Hoare_partition_scheme">
 * Hoare partition scheme (Quicksort) | Wikipedia</a>
 * @see <a href="http://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/">
 * Hoare’s vs Lomuto partition scheme in QuickSort | GeeksforGeeks </a>
 * @bug pivot_index evaluating to less than 0?
 */
void* partition_hoare(void *base, size_t nmbers, size_t size,
                      int (*cmp)(const void *, const void *));

/**
 * @brief Runs a set of test functions on the two main partitioning schemas.
 * @details This will perform the following...
 *  - Randomly generate arrays of integer and floating point types.
 *  - Partitioning each array with Lomuto and Hoare schemas
 *  - Use partition_verify() to demonstrate that the arrays have been
 *      partitioned properly.
 *  - Displaying the passes and failure results to the caller on stdout.
 *      * The seed of the random number generator and size that resulted in a
 *      failure will be recorded to aid in debugging.
 */
void test_partitions(void);

#endif /* SORTING_PARTITION */
