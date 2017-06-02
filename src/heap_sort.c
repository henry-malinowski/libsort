#include "../include/heap_sort.h"


void
hs_build_heap(void* base, size_t nmemb, size_t size,
              int(*cmp)(const void*, const void*))
{
    size_t i;
    for (i = (nmemb/2)-1; i >= 0; --i) {
        /* some heapify call here */
    }
}

void
hs_fixdown(void* base, size_t nmemb, size_t size,
           int(*cmp)(const void*, const void*))
{

}