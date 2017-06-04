/**
 * A C source file that includes a type agnostic merge sort.
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

#include "../include/merge_sort.h"

#include <stdlib.h>
#include <string.h>

char* ms_target;

void
merge_sort(void *base, size_t nmemb, size_t size,
           int(*cmp)(const void *, const void *))
{
    size_t half_memb;
    char* middle_ptr;
    int ms_alloc = 0;

    /* If the target is not allocated, allocate the target array */
    if (ms_target == NULL)
    {
        ms_target = calloc(nmemb, size);
        if (ms_target == NULL)
            exit(2);
        else
            ms_alloc = 1;
    }

    if (nmemb > 1)
    {
        half_memb = nmemb / 2 + nmemb % 2;
        middle_ptr = (char *) base + (half_memb * size);

        merge_sort(base, half_memb, size, cmp);
        merge_sort(middle_ptr, nmemb / 2, size, cmp);
        merge(base, half_memb, nmemb / 2, size, cmp);
    }

    if (ms_alloc == 1)
        free(ms_target);
}


void
merge(void *base, size_t nmemb1, size_t nmemb2, size_t size,
      int(*cmp)(const void *, const void *))
{

    /*       array1: The iterator for moving through the first array
     *       array2: The iterator for moving through the second array
     * array1_limit: The upper bound for array1
     * array2_limit: The upper bound for array2
     *       target: The array to copy array1 and array2 into
     *       t_iter: The iterator for the target array.
     */
    char* array1 = (char*) base;
    char* const array1_limit = (char*) base + size*nmemb1;
    char* array2 = (char*) base + size*nmemb1;
    char* const array2_limit = array2 + size*nmemb2;
    /*
    char* const target = calloc(nmemb1+nmemb2, size);
    if (target == NULL)
    {
        exit(2);
    }
    char* t_iter = target;
    */

    char* t_iter = ms_target;

    /* Copy values from array1 and array2 into target
     * until all the values from one is exhausted
     */
    while (array1 < array1_limit && array2 < array2_limit)
    {
        /* If the element in array1 is greater than
         * or equal to the element in array2
         */
        if (cmp(array1, array2) <= 0)
        {
            memcpy(t_iter, array1, size);
            array1 += size;
        }
        else
        {
            memcpy(t_iter, array2, size);
            array2 += size;
        }

        t_iter += size;
    }

    /* Copy remaining values from array1 if any are left */
    while (array1 < array1_limit)
    {
        memcpy(t_iter, array1, size);
        array1 += size;
        t_iter += size;
    }

    /* Copy remaining values from array2 if any are left */
    while (array2 < array2_limit)
    {
        memcpy(t_iter, array2, size);
        array2 += size;
        t_iter += size;
    }

    /* Copy all the vales of target back into base and free the temp array */
    /*
    memcpy(base, target, size*(nmemb1+nmemb2));
    free(target);
    */
    memcpy(base, ms_target, size*(nmemb1+nmemb2));
}