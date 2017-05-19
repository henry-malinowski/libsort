#ifndef COMPARISONS_FLOATS_H
#define COMPARISONS_FLOATS_H

#ifndef COMPARISONS_FUNC_PTR
#define COMPARISONS_FUNC_PTR
/**
 * @brief Typedef for a comparator function.
 */
typedef int (*cmp_func) (const void *, const void *);
#endif /* COMPARISONS_FUNC_PTR */

int cmp_less_fp32(const void* p, const void* q);

int cmp_less_fp64(const void* p, const void* q);

#endif //COMPARISONS_FLOATS_H
