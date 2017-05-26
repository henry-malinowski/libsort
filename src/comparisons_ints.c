#include <stdint.h>
#include "../include/comparisons_ints.h"

int
cmp_less_uchar(const void* p, const void* q)
{
    const unsigned char a = *(const unsigned char*) p;
    const unsigned char b = *(const unsigned char*) q;

    if (a > b) return +1;
    if (b > a) return -1;
    return 0;
}

int
cmp_less_ushort(const void* p, const void* q)
{
    const unsigned short a = *(const unsigned short*) p;
    const unsigned short b = *(const unsigned short*) q;

    if (a > b) return +1;
    if (b > a) return -1;
    return 0;
}


int
cmp_less_int16(const void* p, const void* q)
{
    const int16_t a = *(const int16_t *)p;
    const int16_t b = *(const int16_t *)q;

    if (a > b) return +1;
    if (b > a) return -1;
    return 0;
}


int
cmp_less_int32(const void* p, const void* q)
{
    const int32_t a = *(const int32_t *)p;
    const int32_t b = *(const int32_t *)q;

    if (a > b) return +1;
    if (b > a) return -1;
    return 0;
}


int
cmp_less_int64(const void* p, const void* q)
{
    const int64_t a = *(const int64_t *)p;
    const int64_t b = *(const int64_t *)q;

    if (a > b) return +1;
    if (b > a) return -1;
    return 0;
}


#include <gmp.h>

#ifdef __GMP_H__
int
cmp_less_intx(const void* p, const void* q)
{
    //return mpz_cmp(*(mpz_t*) p, *(mpz_t*)q);
    return 0;
}

#endif /* __GMP_H__ */
