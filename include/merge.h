#include <stddef.h>

#ifndef SORT_MERGE_H
#define SORT_MERGE_H

/// @warning Calling this function does nothing
void merge(void* base, size_t nmemb, size_t size, int (*cmp)(const void*, const void*));

#endif /* SORT_MERGE_H */
