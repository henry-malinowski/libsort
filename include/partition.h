#include <stddef.h>

#ifndef C_SORTING_LIB_PARTITION_H
#define C_SORTING_LIB_PARTITION_H


int partition_verify(const void* base, size_t nmbers, size_t size,
                     int (*cmp)(const void *, const void *), void* pivot);

/**
 * @brief Partitions are array and returns a pointer to the pivot.
 * @details An input array \p base of length \p nmbers is partitioned in
 *  accordance with the return value of \p cmp. This partition algorithm uses
 *  Lomuto's partition scheme.
 * @details
 * @param base   [in,out] A pointer to the beginning of the array.
 * @param nmbers [in]     The number of items in the array.
 * @param size   [in]     The size of the individual elements of the array.
 * @param cmp    [in]     A comparator function for the sort. This function must
 *  return a integer less than or equal to zero if the first arg is "greater
 *  than or equal" the second arg; this indicates a swap should occur. In other
 *  words this function follows qsort's comparator function pattern.
 * @return A void pointer to the location of the partition.
 * @see <a href="http://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/">
 * Hoare’s vs Lomuto partition scheme in QuickSort | GeeksforGeeks </a>
 */
void* partition_lomuto(void* base, size_t nmbers, size_t size,
                       int (*cmp)(const void *, const void *));


void* hoare_lomuto(void* base, size_t nmbers, size_t size,
                       int (*cmp)(const void *, const void *));


#endif //C_SORTING_LIB_PARTITION_H
