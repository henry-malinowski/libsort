/**
 * @file
 * A C header file that includes a type agnostic network sorting algorithms.
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

#ifndef SORT_NETWORK_H
#define SORT_NETWORK_H

#include <stddef.h>

/**
 * Utilizes a 4-wire sorting network to sort an array.
 * @param base  [in,out] A pointer to the beginning of the array.
 * @param nmemb [in]     The number of items in the array.
 * @param size  [in]     The size of the individual elements of the array.
 * @param cmp   [in]     A comparator function for the sort. This function must
 *  return a negative integer if two elements should be swapped.
 * @note If the \p nmbers does not equal 4, the array may (or may not) be sorted.
 *
 * <b>Example usage:</b>
 * @code{.c}
 *  network_sort_4_wire(array, 4, sizeof(array[0]), cmp_func);
 * @endcode
 * @see <a href="https://en.wikipedia.org/wiki/Sorting_network">
 * Sorting network | Wikipedia</a>
 * @copyright MIT License.
 */
void network_sort_4_wire(void* base, size_t nmemb, size_t size, int (*cmp)(const void*, const void*));


/**
 * Utilizes a 5-wire sorting network to sort an array.
 * @details This network completes sorting in 9 comparisons and at most 9 swaps.
 *  This 5 wire sorting network was generated using the Bose-Nelson Algorithm.
 * @param base  [in,out] A pointer to the beginning of the array.
 * @param nmemb [in]     The number of items in the array.
 * @param size  [in]     The size of the individual elements of the array.
 * @param cmp   [in]     A comparator function for the sort. This function must
 *  return a negative integer if two elements should be swapped.
 * @note If the \p nmbers does not equal 5, the array may (or may not) be sorted.
 *
 * <b>Example usage:</b>
 * @code{.c}
 *  network_sort_5_wire(array, 4, sizeof(array[0]), cmp_func);
 * @endcode
 * @see <a href="https://en.wikipedia.org/wiki/Sorting_network">
 * Sorting network | Wikipedia</a>
 * @see <a href="http://jgamble.ripco.net/cgi-bin/nw.cgi?inputs=5&algorithm=best&output=text">
 * Network for N=5, using Bose-Nelson Algorithm</a>
 * @copyright MIT License.
 */
void network_sort_5_wire(void* base, size_t nmemb, size_t size, int (*cmp)(const void*, const void*));


/**
 * Utilizes a 6-wire sorting network to sort an array.
 * @param base  [in,out] A pointer to the beginning of the array.
 * @param nmemb [in]     The number of items in the array.
 * @param size  [in]     The size of the individual elements of the array.
 * @param cmp   [in]     A comparator function for the sort. This function must
 *  return a negative integer if two elements should be swapped.
 * @note If the \p nmbers does not equal 6, the array may (or may not) be sorted.
 *
 * <b>Example usage:</b>
 * @code{.c}
 *  network_sort_6_wire(array, 6, sizeof(array[0]), cmp_func);
 * @endcode
 *
 * @see <a href="https://en.wikipedia.org/wiki/Sorting_network">
 * Sorting network | Wikipedia</a>
 * @see <a href="http://jgamble.ripco.net/cgi-bin/nw.cgi?inputs=6&algorithm=best&output=text">
 * Network for N=6, using Bose-Nelson Algorithm</a>
 * @copyright MIT License.
 */
void network_sort_6_wire(void* base, size_t nmemb, size_t size, int (*cmp)(const void*, const void*));


/**
 * Utilizes a 7-wire sorting network to sort an array.
 * @param base  [in,out] A pointer to the beginning of the array.
 * @param nmemb [in]     The number of items in the array.
 * @param size  [in]     The size of the individual elements of the array.
 * @param cmp   [in]     A comparator function for the sort. This function must
 *  return a negative integer if two elements should be swapped.
 * @note If the \p nmbers does not equal 7, the array may (or may not) be sorted.
 *
 * <b>Example usage:</b>
 * @code{.c}
 *  network_sort_7_wire(array, 6, sizeof(array[0]), cmp_func);
 * @endcode
 *
 * @see <a href="https://en.wikipedia.org/wiki/Sorting_network">
 * Sorting network | Wikipedia</a>
 * @see <a href="http://jgamble.ripco.net/cgi-bin/nw.cgi?inputs=6&algorithm=best&output=text">
 * Network for N=7, using Bose-Nelson Algorithm</a>
 * @copyright MIT License.
 */
void network_sort_7_wire(void* base, size_t nmemb, size_t size, int (*cmp)(const void*, const void*));


/**
 * Utilizes a 8-wire sorting network to sort an array.
 * @param base  [in,out] A pointer to the beginning of the array.
 * @param nmemb [in]     The number of items in the array.
 * @param size  [in]     The size of the individual elements of the array.
 * @param cmp   [in]     A comparator function for the sort. This function must
 *  return a negative integer if two elements should be swapped.
 * @note If the \p nmbers does not equal 8, the array may (or may not) be sorted.
 *
 * <b>Example usage:</b>
 * @code{.c}
 *  network_sort_4_wire(array, 8, sizeof(array[0]), cmp_func);
 * @endcode
 * @see <a href="https://en.wikipedia.org/wiki/Sorting_network">
 * Sorting network | Wikipedia</a>
 * @copyright MIT License.
 */
void network_sort_8_wire(void* base, size_t nmemb, size_t size, int (*cmp)(const void*, const void*));


#endif /* SORT_NETWORK_H */
