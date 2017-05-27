#include "../include/comparisons_ints.h"
#include <stddef.h>


#define CMP_RETURN_LESS(a, b)   \
    do {                        \
        if (a > b) return +1;   \
        if (b > a) return -1;   \
        return 0;               \
    } while (0)                 \


#define CMP_RETURN_GREAT(a, b)  \
    do {                        \
        if (a < b) return +1;   \
        if (b < a) return -1;   \
        return 0;               \
    } while (0)                 \


int
cmp_less_uchar(const void* p, const void* q)
{
    const unsigned char a = *(const unsigned char*) p;
    const unsigned char b = *(const unsigned char*) q;
    CMP_RETURN_LESS(a, b);
}


int
cmp_less_ushort(const void* p, const void* q)
{
    const unsigned short a = *(const unsigned short*) p;
    const unsigned short b = *(const unsigned short*) q;
    CMP_RETURN_LESS(a, b);
}


int
cmp_less_uint(const void* p, const void* q)
{
    const unsigned int a = *(const unsigned int*) p;
    const unsigned int b = *(const unsigned int*) q;
    CMP_RETURN_LESS(a, b);
}


int
cmp_less_ul(const void* p, const void* q)
{
    const unsigned long a = *(const unsigned long*) p;
    const unsigned long b = *(const unsigned long*) q;
    CMP_RETURN_LESS(a, b);
}


int
cmp_less_size_t(const void* p, const void* q)
{
    const size_t a = *(const size_t*) p;
    const size_t b = *(const size_t*) q;
    CMP_RETURN_LESS(a, b);
}

/* Comparisons for signed and unsigned long-long integer types.
 * These weren't introduced until the C99 standard, so a check has been included
 *  not compile these is on an earlier version of C: C89, C90, C95.
 */
#if __STDC_VERSION__ >= 199901L  /* check if we're compiling in +C99 mode */
int
cmp_less_ull(const void* p, const void* q)
{
    const unsigned long long a = *(const unsigned long long*) p;
    const unsigned long long b = *(const unsigned long long*) q;
    CMP_RETURN_LESS(a, b);
}


int
cmp_less_ll(const void* p, const void* q)
{
    const long long a = *(const long long*) p;
    const long long b = *(const long long*) q;
    CMP_RETURN_LESS(a, b);
}


int
cmp_great_ull(const void* p, const void* q)
{
    const unsigned long long a = *(const unsigned long long*) p;
    const unsigned long long b = *(const unsigned long long*) q;
    CMP_RETURN_GREAT(a, b);
}


int
cmp_great_ll(const void* p, const void* q)
{
    const long long a = *(const long long*) p;
    const long long b = *(const long long*) q;
    CMP_RETURN_GREAT(a, b);
}
#endif /* __STDC_VERSION__ >= 199901L */
