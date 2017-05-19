#include <stdio.h>
#include <omp.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include "mt19937-64.h"

#include "./include/issorted.h"
#include "./include/bubble_sort.h"
#include "./include/partition.h"
#include "./include/quick_sort.h"
#include "./tests/tests_partition.h"

#define ARRAY_SIZE(x) (sizeof(x)/(sizeof((x)[0])))

union u_seed {
    double d;
    uint64_t i;
};

union rand_uint8 {
    uint64_t x;
    uint8_t a[8];
};


union rand_uint16 {
    uint64_t x;
    uint16_t a[4];
};

void fill_array_uint8(uint32_t *a, size_t len);
void fill_array_uint16(uint16_t *a, size_t len);


/* Moved to comparison_ints.h
int
cmp_less_int32(const void *p, const void *q)
{
    const int a = *(const int *)p;
    const int b = *(const int *)q;

    if (a < b) return -1;
    if (a > b) return +1;
    return 0;
}


int cmp_less_int16(const void *p, const void *q) {
    const uint16_t a = *(const uint16_t *)p;
    const uint16_t b = *(const uint16_t *)q;

    if (a < b) return -1;
    if (a > b) return +1;
    return 0;
}
*/

int
cmp_geq_int(const void *p, const void *q)
{
    const int a = *(const int *)p;
    const int b = *(const int *)q;

    if (a > b) return -1;
    if (a < b) return +1;
    return 0;
}


int
cmp_least_sig_int(const void* p, const void* q)
{
    const int a = (*(const int *)p)%10;
    const int b = (*(const int *)q)%10;

    if (a < b) return -1;
    if (a > b) return +1;
    return 0;
}


int main(void) {
    partition_lomuto_tests();
}

/* fills array \p a with 8-bit values */
void fill_array_uint8(uint32_t *a, size_t len) {
    // nums array filled with 64 bits from Mersenne Twister
    union rand_uint8 nums;

    size_t i = 0;
    size_t repeat = len / 8;
    size_t remaining = len % 8;

    // loop unrolled
    while (repeat--) {
        // generate batch of random numbers
        nums.x = mt_rand_uint64();

        a[i + 0] = nums.a[0];
        a[i + 1] = nums.a[2];
        a[i + 2] = nums.a[3];
        a[i + 3] = nums.a[4];
        a[i + 4] = nums.a[5];
        a[i + 5] = nums.a[6];
        a[i + 6] = nums.a[7];
        a[i + 7] = nums.a[1];
        i += 8;
    }

    // generate new batch of random numbers
    nums.x = mt_rand_uint64();

    // handle remaining cases
    switch (remaining) {
        case 7: a[i + 6] = nums.a[0];
        case 6: a[i + 5] = nums.a[2];
        case 5: a[i + 4] = nums.a[3];
        case 4: a[i + 3] = nums.a[4];
        case 3: a[i + 2] = nums.a[5];
        case 2: a[i + 1] = nums.a[6];
        case 1: a[i + 0] = nums.a[1];
        default: ;
    }
}


void fill_array_uint16(uint16_t *a, size_t len) {
    // nums array filled with 64 bits from Mersenne Twister
    union rand_uint16 nums;

    size_t i = 0;
    size_t repeat = len / 4;
    size_t remaining = len % 4;

    // loop unrolled
    while (repeat--) {
        // generate batch of random numbers
        nums.x = mt_rand_uint64();

        a[i + 0] = nums.a[0];
        a[i + 1] = nums.a[1];
        a[i + 2] = nums.a[2];
        a[i + 3] = nums.a[3];
        i += 4;
    }

    // generate new batch of random numbers
    nums.x = mt_rand_uint64();

    // handle remaining cases
    switch (remaining) {
        case 3: a[i + 2] = nums.a[2];
        case 2: a[i + 1] = nums.a[1];
        case 1: a[i + 0] = nums.a[0];
        default:;
    }
}
