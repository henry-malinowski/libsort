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


int main(void) {
    // Declare array of uint32_t
    uint32_t array_int[6] = {0};
    const size_t len_array_int = ARRAY_SIZE(array_int);

    int16_t array_short[16] = {0};
    const size_t len_array_short = ARRAY_SIZE(array_short);
    cmp_func cmp = &cmp_less_int16;

    // fill it with shorts from Mersenne Twister
    uint64_t seed = array_fill_int16_t(array_short, len_array_short, mt_seed, mt_rand_uint64);

    printf("\nMersenne Twister seed: %zu\n\n", seed);

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
    qsort(array_short, len_array_short, sizeof(uint16_t), cmp);
    //insertion_sort(array_short, len_array_short, sizeof(uint16_t), cmp);
    //bubble_sort(array_short, len_array_short, sizeof(uint16_t), cmp);
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

