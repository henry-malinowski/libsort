#include <stdio.h>
#include <omp.h>
#include <stdint.h>
#include <stdlib.h>

#include "mt19937-64.h"

#include "./include/comparisons_floats.h"
#include "include/merge_sort.h"
#include "tests/array_generators.h"
#include "include/issorted.h"
#include "include/bubble_sort.h"
#include "include/selection_sort.h"
#include "include/insertion_sort.h"
#include "include/quick_sort.h"

#define ARRAY_SIZE(x) (sizeof(x)/(sizeof((x)[0])))

union u_seed {
    double d;   /**< Time from omp_get_wtime as a double        */
    uint64_t i; /**< Time from omp_get_wtime as in a uint64_t   */
};


int main(void) {
    // Declare array of floats
    double start, delta;
    size_t const len_array_double = 32;
    double* array_double = calloc(len_array_double, sizeof(double));

    __compar_fn_t cmp = &cmp_great_fp64;

    // fill it with shorts from Mersenne Twister
    start = omp_get_wtime();
    uint64_t seed = array_fill_fp64(array_double, len_array_double, mt_seed, mt_rand_double_1);
    delta = omp_get_wtime() - start;
    printf("Mersenne Twister seed: %zu\n", seed);
    printf("Generated %zu floats in %.4f sec.\n\n", len_array_double, delta);

    //<editor-fold desc="Display contents (array_double pre-sort)">
    if (len_array_double <= 128) {
        for (size_t i = 0; i < len_array_double; ++i) {
            printf("%0.4f, ", array_double[i]);
            if ((i + 1) % 16 == 0) printf("\n");
        }
        printf("\n\n");
    }
    //</editor-fold>

    start = omp_get_wtime();
    //qsort(array_double, len_array_double, sizeof(double), cmp);
    //insertion_sort(array_double, len_array_double, sizeof(double), cmp);
    //selection_sort(array_double, len_array_double, sizeof(double), cmp);
    //bubble_sort(array_double, len_array_double, sizeof(double), cmp);
    //merge_sort(array_double, len_array_double, sizeof(double), cmp);
    quick_sort(array_double, len_array_double, sizeof(double), cmp);
    delta = omp_get_wtime() - start;

    //<editor-fold desc="Check if the array is sorted">
    int issort = issorted(array_double, len_array_double, sizeof(double), cmp);
    if (issort) {
        printf("array is sorted in %.4f sec.\n", delta);
    } else {
        printf("\narray is not sorted\n");
    }
    //</editor-fold>

    //<editor-fold desc="Display contents (array_double)">
    if (len_array_double <= 128) {
        for (size_t i = 0; i < len_array_double; ++i) {
            printf("%0.4f, ", array_double[i]);
            if ((i+1)% 16 == 0) printf("\n");
        }
        printf("\n");
    }
    //</editor-fold>

    free(array_double);
}

