#include <stdint.h>

#include "../include/comparisons_ints.h"

int
cmp_less_int16(const void *p, const void *q) {
    const int16_t a = *(const int16_t *)p;
    const int16_t b = *(const int16_t *)q;

    if (a > b) return +1;
    if (b > a) return -1;
    return 0;
}


int
cmp_less_int32(const void *p, const void *q)
{
    const int32_t a = *(const int32_t *)p;
    const int32_t b = *(const int32_t *)q;

    if (a > b) return +1;
    if (b > a) return -1;
    return 0;
}


int
cmp_less_int64(const void *p, const void *q)
{
    const int64_t a = *(const int64_t *)p;
    const int64_t b = *(const int64_t *)q;

    if (a > b) return +1;
    if (b > a) return -1;
    return 0;
}
