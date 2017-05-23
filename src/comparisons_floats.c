#include "../include/comparisons_floats.h"

/* Less than functions */
int
cmp_less_fp32(const void* p, const void* q)
{
    const float a = *(const float*) p;
    const float b = *(const float*) q;

    if (a > b) return +1;
    if (b > a) return -1;
    return 0;
}


int
cmp_less_fp64(const void* p, const void* q)
{
    const double a = *(const double *) p;
    const double b = *(const double *) q;

    if (a > b) return +1;
    if (b > a) return -1;
    return 0;
}


int
cmp_less_fp128(const void *p, const void *q)
{
    const long double a = *(const long double *) p;
    const long double b = *(const long double *) q;

    if (a > b) return +1;
    if (b > a) return -1;
    return 0;
}

/* Greater-then functions */
int
cmp_great_fp32(const void* p, const void* q)
{
    const float a = *(const float*) p;
    const float b = *(const float*) q;

    if (b > a) return +1;
    if (a > b) return -1;
    return 0;
}


int
cmp_great_fp64(const void* p, const void* q)
{
    const double a = *(const double *) p;
    const double b = *(const double *) q;

    if (b > a) return +1;
    if (a > b) return -1;
    return 0;
}


int
cmp_great_fp128(const void *p, const void *q)
{
    const long double a = *(const long double *) p;
    const long double b = *(const long double *) q;

    if (b > a) return +1;
    if (a > b) return -1;
    return 0;
}
