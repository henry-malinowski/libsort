/**
 * @file
 * A header file that includes a type agnostic sorting status checker.
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

#ifndef SORT_IS_SORTED_H
#define SORT_IS_SORTED_H

/**
 * Verifies that an array of an arbitrary type is sorted.
 * @details This function uses a tight loop to compare each element with the
 *  previous element starting from the second element. If the comparison loop
 *  breaks early the comparison between iterator and \p nmbers will fail.
 *  Likewise, if the loop is broken be reaching the limit of the array then the
 *  length comparison will succeed and the array has been found to be sorted in
 *  accordance with \p cmp.
 * @param base   A pointer to the beginning of the array.
 * @param nmbers The number of items in the array.
 * @param size   The size of the individual elements of the array.
 * @param cmp    A comparator function for checking the "sortedness". This
 *  function returns a value less or equal to 0 when \c array[0] is "less than
 *  or equal" to \c array[1].
 * @return An int acting as a boolean value.
 * @retval 0 if the array is not sorted in accordance with \p cmp.
 * @retval 1 if the array is sorted in accordance with \p cmp.
 *
 * <b>Example usage:</b>
 * @code{.c}
 *  issorted(array, sizeof(array)/sizeof(array[0]), sizeof(array[0]), cmp_func);
 * @endcode
 * @copyright MIT License.
 */
int issorted(const void *base, size_t nmbers, size_t size, int (*cmp)(const void*, const void*));

#endif //SORT_IS_SORTED_H
