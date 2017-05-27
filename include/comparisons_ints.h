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

/* implementation defined comparators */
int cmp_less_uchar(const void* p, const void* q);
int cmp_less_ushort(const void* p, const void* q);
int cmp_less_uint(const void* p, const void* q);
int cmp_less_ul(const void* p, const void* q);
int cmp_less_size_t(const void* p, const void* q);


#if __STDC_VERSION__ >= 199901L /* check if we're compiling in +C99 mode */
int cmp_less_ull(const void* p, const void* q);
int cmp_great_ull(const void* p, const void* q);
int cmp_less_ll(const void* p, const void* q);
int cmp_great_ull(const void* p, const void* q);
#endif /* __STDC_VERSION__ >= 199901L */

#endif /* COMPARISONS_INTS_H */
