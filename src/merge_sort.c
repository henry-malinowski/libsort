#include "../include/merge_sort.h"

#include <stdlib.h>
#include <string.h>


void
merge_sort(void* base, size_t nmemb, size_t size,
           int(*cmp)(const void*, const void*))
{

}


void
merge(void* base, size_t nmemb1, size_t nmemb2, size_t size,
           int(*cmp)(const void*, const void*))
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
    char* const target = calloc(nmemb1+nmemb2, size);
    if (target == NULL) {
        exit(1);
    }
    char* t_iter = target;

    /* Copy values from array1 and array2 into target
     * until all the values from one is exhausted
     */
    while (array1 < array1_limit && array2 < array2_limit)
    {
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
    memcpy(base, target, size*(nmemb1+nmemb2));
    free(target);
}