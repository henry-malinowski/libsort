#ifndef COMPARISONS_GMP_H
#define COMPARISONS_GMP_H

/**
 * @brief Compare less than two integers of the mpz_t type from the GNU Multiple
 * Precision Arithmetic Library.
 * @details This function is a wrapper for calling the function mpz_cmp in such
 *  a way that is compatible with stdlib.h qsort and other type-agnostic
 *  sorting functions.
 * @param p, q Pointers to mpz_t int types to be compared.
 * @returns An int corresponding to the order of the values of \p p and \p q.
 * @retval +1: Indicates that \p p is strictly greater than \p q.
 * @retval -1: Indicates that \p p is strictly less than \p q.
 * @retval  0: Indicates that the value at \p p and \p q are equal.
 * @see <a href="https://gmplib.org/manual/Integer-Comparisons.html">
 * Comparison Functions | GMPLib Manual</a>
 * @warning This code is untested and is not guaranteed to return the documented
 *  result.
 */
int cmp_less_intx(const void* p, const void* q);

int cmp_great_intx(const void* p, const void* q);

#endif /* COMPARISONS_GMP_H */
