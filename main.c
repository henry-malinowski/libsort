#include <stdio.h>
#include <omp.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include "mt19937-64.h"

#include "./include/insertion_sort.h"
#include "./include/selection_sort.h"
#include "./include/issorted.h"
#include "./include/network_sorting.h"
#include "./include/bubble_sort.h"
#include "./include/partition.h"
#include "./include/quick_sort.h"

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


int
cmp_leq_int(const void *p, const void *q)
{
    const int a = *(const int *)p;
    const int b = *(const int *)q;

    if (a < b) return -1;
    if (a > b) return +1;
    return 0;
}


int cmp_leq_short(const void *p, const void *q) {
    const uint16_t a = *(const uint16_t *)p;
    const uint16_t b = *(const uint16_t *)q;

    if (a < b) return -1;
    if (a > b) return +1;
    return 0;
}


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
    //<editor-fold desc="Seed PRNG (Mersenne Twister)">
    union u_seed seed;
    seed.d = omp_get_wtime();
    mt_seed(seed.i);
    //mt_seed(4676236608565431931ULL);
    printf("\nMersenne Twister seed: %zu\n\n", seed.i);
    //</editor-fold>

    // Declare array of uint32_t
    uint32_t array_int[6] = {0};
    const size_t len_array_int = ARRAY_SIZE(array_int);

    uint16_t array_short[32] = {0};
    const size_t len_array_short = ARRAY_SIZE(array_short);

    // fill it with 8-bit numbers from Mersenne Twister
    fill_array_uint16(array_short, len_array_short);

    void* cmp = &cmp_leq_short;

    //<editor-fold desc="Display contents (array_short pre-sort)">
    if (len_array_short <= 128) {
        for (size_t i = 0; i < len_array_short; ++i) {
            printf("%5hu, ", array_short[i]);
            if ((i + 1) % 16 == 0) printf("\n");
        }
        printf("\n");
    }
    //</editor-fold>gi


    double start = omp_get_wtime();
    //qsort(array_short, len_array_short, sizeof(uint16_t), cmp);
    //selection_sort(array_short, len_array_short, sizeof(uint16_t), cmp);
    //bubble_sort(array_short, len_array_short, sizeof(uint16_t), cmp);
    void* piv = partition_hoare(array_short, len_array_short, sizeof(uint16_t), cmp);
    //quick_sort(array_short, len_array_short, sizeof(uint16_t), cmp);
    double delta = omp_get_wtime() - start;

    //<editor-fold desc="Check if the array is partitioned">
    int isPart = partition_verify(array_short, len_array_short, sizeof(uint16_t), cmp, piv);
    if (isPart) {
        printf("array is partitioned in %.4f sec.\n", delta);
    } else {
        printf("\narray is not partitioned\n");
    }
    //</editor-fold>

    //<editor-fold desc="Display contents (array_int)">
    if (len_array_short <= 128) {
        for (size_t i = 0; i < len_array_short; ++i) {
            printf("%5hu, ", array_short[i]);
            if ((i+1)% 16 == 0) printf("\n");
        }
    }
    //</editor-fold>

    printf("partition is the %zu th element (%p), value of %hu\n",
           (piv - (void*)array_short)/sizeof(array_short[0]), piv, *(uint16_t*)piv);

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
        case 7: a[i + 6] = nums.a[i + 0];
        case 6: a[i + 5] = nums.a[i + 2];
        case 5: a[i + 4] = nums.a[i + 3];
        case 4: a[i + 3] = nums.a[i + 4];
        case 3: a[i + 2] = nums.a[i + 5];
        case 2: a[i + 1] = nums.a[i + 6];
        case 1: a[i + 0] = nums.a[i + 1];
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
        case 3: a[i + 2] = nums.a[i + 2];
        case 2: a[i + 1] = nums.a[i + 1];
        case 1: a[i + 0] = nums.a[i + 0];
        default:;
    }
}
