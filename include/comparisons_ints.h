#ifndef COMPARISONS_INTS_H
#define COMPARISONS_INTS_H

#ifndef COMPARE_FUNC_PTR
#define COMPARE_FUNC_PTR
/**
 * @brief Typedef for a comparator function.
 */
typedef int (*cmp_func) (const void *, const void *);
#endif /* COMPARE_FUNC_PTR */

int cmp_less_int16(const void *p, const void *q);
int cmp_less_int32(const void *p, const void *q);
int cmp_less_int64(const void *p, const void *q);

#endif /* COMPARISONS_INTS_H */
