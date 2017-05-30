#include <stdio.h>
#include <omp.h>
#include <stdint.h>
#include <stdlib.h>

#include "mt19937-64.h"

#include "./include/comparisons_floats.h"
#include "include/merge_sort.h"
#include "tests/array_generators.h"
#include "include/issorted.h"

#define ARRAY_SIZE(x) (sizeof(x)/(sizeof((x)[0])))

union u_seed {
    double d;
    uint64_t i;
};


int main(void) {
    // Declare array of uint32_t
    float array_float[8409] = {0};
    const size_t len_array_float = ARRAY_SIZE(array_float);

    __compar_fn_t cmp = &cmp_less_fp32;

    // fill it with shorts from Mersenne Twister
    uint64_t seed = array_fill_fp32(array_float, len_array_float, mt_seed, rand_float);
    printf("Mersenne Twister seed: %zu\n", seed);
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
    //qsort(array_float, len_array_float, sizeof(float), cmp);
    //insertion_sort(array_float, len_array_float, sizeof(float), cmp);
    //selection_sort(array_float, len_array_float, sizeof(float), cmp);
    //bubble_sort(array_float, len_array_float, sizeof(float), cmp);
    merge_sort(array_float, len_array_float, sizeof(float), cmp);
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

