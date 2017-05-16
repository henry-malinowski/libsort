/**
 * @file
 * A header file that includes a type agnostic Fisher-Yates shuffle.
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

#ifndef SHUFFLE_H
#define SHUFFLE_H

/**
 * Performs a Fisher-Yates shuffle shuffle on an arbitrarily typed array.
 * @param base      [in,out] A pointer to the beginning of the array.
 * @param nmbers    [in]    The number of items in the array.
 * @param size      [in]    The size of the individual elements of the array.
 * @param r_func    [in]    The random number generator for shuffling the data.
 *
 * Example usage:
 * @code{.c}
 *  shuffle(array, sizeof(array)/sizeof(array[0]), sizeof(array[0]), rand_wrapper)
 * @endcode
 * @see <a href="https://en.wikipedia.org/wiki/Fisher?Yates_shuffle">
 * Fisher-Yates shuffle | Wikipedia</a>
 * @copyright GNU Public License.
 */
void shuffle(void *base, size_t nmbers, size_t size, size_t (*r_func)(void));


#endif //SHUFFLE_H
