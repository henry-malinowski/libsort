/**
 * A source file that includes a type agnostic sorting status checker.
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

#include "../include/issorted.h"
int
issorted(const void *base, size_t nmbers, size_t size,
         int (*cmp)(const void*, const void*))
{
    /* - Set up main iterator.
     * - Set up the moving pointers so that multiplication
     *   is not needed to calculate the memory addresses.
     */
    register size_t i;
    register const void* a = base;
    register const void* b = base + size;

    // loop over array
    for (i = 1; i < nmbers && (cmp(a, b) <= 0); ++i)
    {
        /* recalculate the pointers */
        a = b;
        b += size;
    }

    /* check the iterator against the number of members  */
    return i == nmbers;
}

