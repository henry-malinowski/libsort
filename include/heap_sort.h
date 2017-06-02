#include <stddef.h>

#ifndef SORT_HEAP_H
#define SORT_HEAP_H

/**
 * @brief Performs heap sort on an arbitrarily typed array.
 * @param base   [in,out] A pointer to the beginning of the array.
 * @param nmbers [in]     The number of items in the array.
 * @param size   [in]     The size of the individual elements of the array.
 * @param cmp    [in]     A comparator function for the sort. This function must
 *  return a negative integer if the first arg is "greater than" the second arg;
 *  this indicates a swap should occur. In other words this function follows
 *  qsort's comparator function pattern.
 *
 * <b>Example usage:</b>
 * @code{.c}
 *  heap_sort(array, ARRAY_SIZE(array), sizeof(array[0]), cmp_func);
 * @endcode
 * @see <a href="https://en.wikipedia.org/wiki/Heapsort">
 * Heapsort | Wikipedia</a>
 * @copyright MIT License.
 */
void heap_sort(void* base, size_t nmemb, size_t size,
               int(*cmp)(const void*, const void*));

/**
 * @brief Takes an array and builds the array into a max heap.
 */
void hs_build_heap(void* base, size_t nmemb, size_t size,
                   int(*cmp)(const void*, const void*));


void hs_heapify(void* base, size_t nmemb, size_t size,
                int(*cmp)(const void*, const void*));

/**
 * @brief Fixes a heap that has had it's top-parent swapped with a lower child.
 */
void hs_fixdown(void* base, size_t nmemb, size_t size,
                int(*cmp)(const void*, const void*));

#endif /* SORT_HEAP_H */
