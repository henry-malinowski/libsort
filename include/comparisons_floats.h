/*
 * While their may be opportunities for optimizing the cmp functions, analysis
 * of the assembly output of three different compilers (GCC, Clang, ARM64 GCC)
 * with -O2 optimizations enabled produced almost identical code to supposedly
 * more optimal variations.
 */

#ifndef COMPARISONS_FLOATS_H
#define COMPARISONS_FLOATS_H

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

/**
 * @brief Compares two floating point values.
 * @details The return value from this function is in accordance with the
 *  pattern outlined for a comparison function used by qsort.
 * @param p, q Pointers to floats to be compared.
 * @returns An int corresponding to the order of the values of \p p and \p q.
 * @retval +1: Indicates that \p p is strictly greater than \p q.
 * @retval -1: Indicates that \p p is strictly less than \p q.
 * @retval  0: Indicates that the values at \p p and \p q are equal.
 * @see <a href="https://www.gnu.org/software/libc/manual/html_node/Comparison-Functions.html">
 * GCC libc Software Manuel | 9.1 Defining the Comparison Function</a>
 */
int cmp_less_fp32(const void* p, const void* q);


/**
 * @brief Compares two double-precision floating point values.
 * @details The return value from this function is in accordance with the
 *  pattern outlined for a comparison function used by qsort.
 * @param p, q Pointers to doubles to be compared.
 * @returns An int corresponding to the order of the values of \p p and \p q.
 * @retval +1: Indicates that \p p is strictly greater than \p q.
 * @retval -1: Indicates that \p p is strictly less than \p q.
 * @retval  0: Indicates that the values at \p p and \p q are equal.
 * @see <a href="https://www.gnu.org/software/libc/manual/html_node/Comparison-Functions.html">
 * GCC libc Software Manuel | 9.1 Defining the Comparison Function</a>
 */
int cmp_less_fp64(const void* p, const void* q);


/**
 * @brief Compares two 'long-double' floating point values.
 * @details The return value from this function is in accordance with the
 *  pattern outlined for a comparison function used by qsort. The exact
 *  precision of this function is platform and compiler dependant, on some
 *  platforms this may be an 80-bit, 96-bit, or even an 128-bit floating point
 *  value.
 * @param p, q Pointers to long-doubles to be compared.
 * @returns An int corresponding to the order of the values of \p p and \p q.
 * @retval +1: Indicates that \p p is strictly greater than \p q.
 * @retval -1: Indicates that \p p is strictly less than \p q.
 * @retval  0: Indicates that the value at \p p and \p q are equal.
 * @see <a href="https://www.gnu.org/software/libc/manual/html_node/Comparison-Functions.html">
 * GCC libc Software Manuel | 9.1 Defining the Comparison Function</a>
 */
int cmp_less_fp128(const void *p, const void *q);


/**
 * @brief Compares two floating point values.
 * @details The return value from this function is in accordance with the
 *  pattern outlined for a comparison function used by qsort.
 * @param p, q Pointers to doubles to be compared.
 * @returns An int corresponding to the order of the values of \p p and \p q.
 * @retval +1: Indicates that \p q is strictly greater than \p p.
 * @retval -1: Indicates that \p q is strictly less than \p p.
 * @retval  0: Indicates that the values at \p p and \p q are equal.
 * @see <a href="https://www.gnu.org/software/libc/manual/html_node/Comparison-Functions.html">
 * GCC libc Software Manuel | 9.1 Defining the Comparison Function</a>
 */
int cmp_great_fp32(const void* p, const void* q);


/**
 * @brief Compares two double-precision floating point values.
 * @details The return value from this function is in accordance with the
 *  pattern outlined for a comparison function used by qsort.
 * @param p, q Pointers to doubles to be compared.
 * @returns An int corresponding to the order of the values of \p p and \p q.
 * @retval +1: Indicates that \p q is strictly greater than \p p.
 * @retval -1: Indicates that \p q is strictly less than \p p.
 * @retval  0: Indicates that the values at \p p and \p q are equal.
 * @see <a href="https://www.gnu.org/software/libc/manual/html_node/Comparison-Functions.html">
 * GCC libc Software Manuel | 9.1 Defining the Comparison Function</a>
 */
int cmp_great_fp64(const void* p, const void* q);


/**
 * @brief Compares two 'long-double' floating point values.
 * @details The return value from this function is in accordance with the
 *  pattern outlined for a comparison function used by qsort. The exact
 *  precision of this function is platform and compiler dependant, on some
 *  platforms this may be an 80-bit, 96-bit, or even an 128-bit floating point
 *  value.
 * @param p, q Pointers to long-doubles to be compared.
 * @returns An int corresponding to the order of the values of \p p and \p q.
 * @retval +1: Indicates that \p q is strictly greater than \p p.
 * @retval -1: Indicates that \p q is strictly less than \p p.
 * @retval  0: Indicates that the values at \p p and \p q are equal.
 * @see <a href="https://www.gnu.org/software/libc/manual/html_node/Comparison-Functions.html">
 * GCC libc Software Manuel | 9.1 Defining the Comparison Function</a>
 */
int cmp_great_fp128(const void* p, const void* q);


#endif /* COMPARISONS_FLOATS_H */
