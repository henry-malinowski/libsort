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
#include "./include/comparisons_floats.h"
#include "include/insertion_sort.h"

#define ARRAY_SIZE(x) (sizeof(x)/(sizeof((x)[0])))

union u_seed {
    double d;
    uint64_t i;
};


int main(void) {
    // Declare array of uint32_t
    float array_float[19200] = {0};
    const size_t len_array_float = ARRAY_SIZE(array_float);

    cmp_func cmp = &cmp_less_fp32;

    // fill it with shorts from Mersenne Twister
    uint64_t seed = array_fill_fp32(array_float, len_array_float, mt_seed, rand_float);
    printf("\nMersenne Twister seed: %zu\n", seed);
    printf("Generated %zu floats\n\n", len_array_float);

    //<editor-fold desc="Display contents (array_float pre-sort)">
    if (len_array_float <= 128) {
        for (size_t i = 0; i < len_array_float; ++i) {
            printf("%6.2f, ", array_float[i]);
            if ((i + 1) % 16 == 0) printf("\n");
        }
        printf("\n");
    }
    printf("\n");
    //</editor-fold>

    double start = omp_get_wtime();
    //qsort(array_short, len_array_short, sizeof(uint16_t), cmp);
    //insertion_sort(array_float, len_array_float, sizeof(float), cmp);
    //bubble_sort(array_float, len_array_float, sizeof(float), cmp);
    //void* piv = partition_lomuto(array_short, len_array_short, sizeof(uint16_t), cmp);
    quick_sort(array_float, len_array_float, sizeof(float), cmp);
    double delta = omp_get_wtime() - start;

    //<editor-fold desc="Check if the array is sorted">
    int issort = issorted(array_float, len_array_float, sizeof(float), cmp);
    if (issort) {
        printf("array is sorted in %.4f sec.\n", delta);
    } else {
        printf("\narray is not sorted\n");
    }
    //</editor-fold>

    //<editor-fold desc="Display contents (array_float)">
    if (len_array_float <= 128) {
        for (size_t i = 0; i < len_array_float; ++i) {
            printf("%6.2f, ", array_float[i]);
            if ((i+1)% 16 == 0) printf("\n");
        }
    }
    printf("\n");
    //</editor-fold>
}

