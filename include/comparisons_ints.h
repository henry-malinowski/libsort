#ifndef COMPARISONS_INTS_H
#define COMPARISONS_INTS_H

#include <stddef.h>

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


/* Signed less-than comparators */
int cmp_lt_char(const void* p, const void* q);
int cmp_lt_short(const void* p, const void* q);
int cmp_lt_int(const void* p, const void* q);
int cmp_lt_long(const void* p, const void* q);


/* Unsigned less-then comparators */
int cmp_lt_uchar(const void* p, const void* q);
int cmp_lt_ushort(const void* p, const void* q);
int cmp_lt_uint(const void* p, const void* q);
int cmp_lt_ulong(const void* p, const void* q);
int cmp_lt_size_t(const void* p, const void* q);


/* Signed greater-than comparators */
int cmp_gt_char(const void* p, const void* q);
int cmp_gt_short(const void* p, const void* q);
int cmp_gt_int(const void* p, const void* q);
int cmp_gt_long(const void* p, const void* q);
int cmp_gt_ssize_t(const void* p, const void* q);


/* Unsigned greater-then comparators */
int cmp_gt_uchar(const void* p, const void* q);
int cmp_gt_ushort(const void* p, const void* q);
int cmp_gt_uint(const void* p, const void* q);
int cmp_gt_ulong(const void* p, const void* q);


/* Comparisons for signed and unsigned long-long integer types.
 * These weren't introduced until the C99 standard, so a check has been included
 *  not compile these is on an earlier version of C: C89, C90, C95.
 */
#if __STDC_VERSION__ >= 199901L
int cmp_lt_ll(const void* p, const void* q);
int cmp_gt_ll(const void* p, const void* q);
int cmp_lt_ull(const void* p, const void* q);
int cmp_gt_ull(const void* p, const void* q);
#endif /* __STDC_VERSION__ >= 199901L */

#endif /* COMPARISONS_INTS_H */
