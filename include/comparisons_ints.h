#ifndef COMPARISONS_INTS_H
#define COMPARISONS_INTS_H

#ifndef __compar_fn_t_defined
#define __compar_fn_t_defined
/**
 * @brief Typedef for a comparator function.
 */
typedef int (*__compar_fn_t) (const void *, const void *);
#endif /* __compar_fn_t_defined */

int cmp_less_int16(const void *p, const void *q);
int cmp_less_int32(const void *p, const void *q);
int cmp_less_int64(const void *p, const void *q);

#endif /* COMPARISONS_INTS_H */
