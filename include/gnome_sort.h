/**
 * @file
 * A header file that includes a type agnostic Gnome sort.
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

#include <stdlib.h> /* size_t */

#ifndef SORT_GNOME_H
#define SORT_GNOME_H

/**
 * Performs gnome sort on an arbitrarily typed array.
 * @param base   [in,out] A pointer to the beginning of the array.
 * @param nmbers [in]     The number of items in the array.
 * @param size   [in]     The size of the individual elements of the array.
 * @param cmp    [in]     A comparator function for the sort. This function must
 *  return a value greater than zero if two elements should be swapped.
 *
 * Example usage:
 * @code{.c}
 *  gnome_sort(array, sizeof(array)/sizeof(array[0]), sizeof(array[0]), cmp_func);
 * @endcode
 * @see <a href="https://en.wikipedia.org/wiki/Gnome_sort">
 * Gnome sort | Wikipedia</a>
 * @copyright MIT License.
 */
void gnome_sort(void *base, size_t nmemb, size_t size, int (*cmp)(const void*, const void*));

#endif /* SORT_GNOME_H */
