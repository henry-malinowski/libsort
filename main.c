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
#include "./tests/array_generators.h"
#include "./tests/tests_partition.h"
#include "./include/comparisons_ints.h"
#include "include/insertion_sort.h"

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

int main(void) {
    //<editor-fold desc="Seed PRNG (Mersenne Twister)">
    union u_seed seed;
    seed.d = omp_get_wtime();
    mt_seed(seed.i);
    //mt_seed(4659345558749990174ULL);
    printf("\nMersenne Twister seed: %zu\n\n", seed.i);
    //</editor-fold>

    // Declare array of uint32_t
    uint32_t array_int[6] = {0};
    const size_t len_array_int = ARRAY_SIZE(array_int);

    int16_t array_short[64] = {0};
    const size_t len_array_short = ARRAY_SIZE(array_short);

    // fill it with 16-bit numbers from Mersenne Twister
    array_fill_int16_t(array_short, len_array_short, mt_seed, mt_rand_uint64);

    cmp_func cmp = &cmp_less_int16;

    //<editor-fold desc="Display contents (array_short pre-sort)">
    if (len_array_short <= 128) {
        for (size_t i = 0; i < len_array_short; ++i) {
            printf("%6d, ", array_short[i]);
            if ((i + 1) % 16 == 0) printf("\n");
        }
        printf("\n");
    }
    //</editor-fold>


    double start = omp_get_wtime();
    //qsort(array_short, len_array_short, sizeof(uint16_t), cmp);
    //insertion_sort(array_short, len_array_short, sizeof(uint16_t), cmp);
    bubble_sort(array_short, len_array_short, sizeof(uint16_t), cmp);
    //void* piv = partition_lomuto(array_short, len_array_short, sizeof(uint16_t), cmp);
    //quick_sort(array_short, len_array_short, sizeof(uint16_t), cmp);
    double delta = omp_get_wtime() - start;

    //<editor-fold desc="Check if the array is sorted">
    int issort = issorted(array_short, len_array_short, sizeof(uint16_t), cmp);
    if (issort) {
        printf("array is sorted in %.4f sec.\n", delta);
    } else {
        printf("\narray is not sorted\n");
    }
    //</editor-fold>

    //<editor-fold desc="Display contents (array_int)">
    if (len_array_short <= 128) {
        for (size_t i = 0; i < len_array_short; ++i) {
            printf("%6d, ", array_short[i]);
            if ((i+1)% 16 == 0) printf("\n");
        }
    }
    printf("\n");
    //</editor-fold>
}

