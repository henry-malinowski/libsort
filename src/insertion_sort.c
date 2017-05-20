/**
 * A C source file that includes a type agnostic insertion sort.
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

#include "../include/insertion_sort.h"

#ifndef SIZE_MAX
#define SIZE_MAX ((size_t) - 1)
#endif

void
insertion_sort(void *base, size_t nmbers, size_t size,
               int (*cmp)(const void*, const void*))
{
    /* - Allocate iterators
     * - Allocate temp variable
     * - Check that malloc() successfully allocated size bytes.
     *  + On failure: return early
     *  + On success: continue
     */
    register size_t i, j;
    void* temp = malloc(size);
    char* b_ptr = (char*) base;

    if (temp == NULL) return;

    /* for i = 1 to length(A) */
    for (i = 1; i < nmbers; ++i)
    {
        memcpy(temp, b_ptr+(i*size), size);                  /* temp = A[i]    */
        j = i - 1;                                          /* j <- i - 1     */

        /* while j > 0 and A[j] > A[j-1] */
        while ((j != SIZE_MAX) && cmp( b_ptr+(j*size), temp) > 0)
        {
            memcpy(b_ptr+((j+1)*size), b_ptr+(j*size), size); /* A[j+1] <- A[j] */
            --j;                                            /* j <- j - 1     */
        }

        memcpy(b_ptr+((j+1) * size), temp, size);            /* A[j+1] = temp  */
    }

    /* Free our memory */
    free(temp);
}