#include <stddef.h>

#ifndef SORT_MERGE_H
#define SORT_MERGE_H

void merge_sort(void *base, size_t nmemb, size_t size,
                int(*cmp)(const void *, const void *));

/**
 * @brief Merges two portions of contiguous memory.
 * @details Merge, combines two contiguous portions of memory in order in
 *  accordance with the return value of \p cmp. The starting point of the
 *  contiguous memory is defined to the \p base. The first portion ends at...
 *  \code{.c}
 *      void* bound = base + (size * nmemb1);
 *  \endcode
 *  This is also beginning of the second portion of memory to merge. This second
 *  portion of memory is defined to end at...
 *  \code{.c}
 *      void* end = bound + (size * nmemb2);
 *  \endcode
 * If the sub-array aren't sorted, then the output in \p base will not sorted.
 * @param base [in,out] The beginning of the contiguous portion of memory to
 *  merge to and from. This must be valid allocated memory from \c base to
 *  \code{.c}
 *      base + size * (nmemb1 + nmemb2);
 *  \endcode If this is not valid, segmentation faults will occur.
 * @param nmemb1 [in] The number of elements in the first portion of memory.
 * @param nmemb2 [in] The number of elements in the second portion of memory.
 * @param size [in] The size of the individual elements of the array.
 * @param cmp [in] A comparator function for the sort. This function must
 *  return a negative integer if the first arg is "greater than" the second arg;
 *  this indicates a swap should occur. In other words this function follows
 *  qsort's comparator function pattern.
 * @returns A non-zero value if memory allocation failed.
 * <b>Example usage:</b>
 * @code{.c}
 *  merge(array, 10, 10, sizeof(array[0]), cmp_func);
 * @endcode
 * @see <a href="https://en.wikipedia.org/wiki/Merge_sort">
 *  Merge Sort | Wikipedia </a>
 */
void merge(void* base, size_t nmemb1, size_t nmemb2, size_t size,
           int(*cmp)(const void *, const void *));

#endif /* SORT_MERGE_H */
