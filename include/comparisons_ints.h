#ifndef COMPARISONS_INTS_H
#define COMPARISONS_INTS_H

#ifndef __compar_fn_t_defined
#define __compar_fn_t_defined
/**
 * @brief Typedef for a comparator function.
 * @details This definition is intended to give the file including this header a
 *  type for specifying a comparison function if they have not included the
 *  nearly identical typedef from stdlib.h .
 */
typedef int (*__compar_fn_t) (const void *, const void *);
#endif /* __compar_fn_t_defined */

int cmp_less_int16(const void* p, const void* q);
int cmp_less_int32(const void* p, const void* q);
int cmp_less_int64(const void* p, const void* q);

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

#endif /* COMPARISONS_INTS_H */
