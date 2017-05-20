#include "../include/merge.h"
#include "../include/merge_sort.h"

void
merge_sort(void* base, size_t nmemb, size_t size,
           int (*cmp)(const void*, const void*))
{
    char* half_ptr = (char*) base + ((nmemb/2)*size);
    if (nmemb <= 1) return;

    merge_sort(base, nmemb/2, size, cmp);
    merge_sort(half_ptr, nmemb/2+nmemb%2, size, cmp);
    merge(base, nmemb, size, cmp);
}

