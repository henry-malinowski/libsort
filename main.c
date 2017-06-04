#include <stdio.h>
#include <omp.h>
#include <stdint.h>
#include <stdlib.h>

#include "mt19937-64.h"

#include "./include/comparisons_stdint.h"
#include "include/merge_sort.h"
#include "tests/array_generators.h"
#include "include/issorted.h"
#include "include/bubble_sort.h"
#include "include/selection_sort.h"
#include "include/insertion_sort.h"
#include "include/quick_sort.h"
#include "include/heap_sort.h"

#define ARRAY_SIZE(x) (sizeof(x)/(sizeof((x)[0])))

int main(void) {
    // Declare array of floats
    double start, delta;
    size_t const len_array_int = 2541684;
    int32_t* array_int = calloc(len_array_int, sizeof(int32_t));

    __compar_fn_t cmp = cmp_less_int32;

    // fill it with shorts from Mersenne Twister
    start = omp_get_wtime();
    uint64_t seed = array_fill_int32_t(array_int, len_array_int, mt_seed, mt_rand_uint64);
    delta = omp_get_wtime() - start;
    printf("Mersenne Twister seed: %zu\n", seed);
    printf("Generated %zu floats in %.4f sec.\n\n", len_array_int, delta);

    //<editor-fold desc="Display contents (array_int pre-sort)">
    if (len_array_int <= 128) {
        for (size_t i = 0; i < len_array_int; ++i) {
            printf("%3d, ", array_int[i]);
            if ((i + 1) % 16 == 0) printf("\n");
        }
        printf("\n\n");
    }
    //</editor-fold>

    start = omp_get_wtime();
    //qsort(array_int, len_array_int, sizeof(int), cmp);
    //insertion_sort(array_int, len_array_int, sizeof(int), cmp);
    //selection_sort(array_int, len_array_int, sizeof(int), cmp);
    //bubble_sort(array_int, len_array_int, sizeof(int), cmp);
    merge_sort(array_int, len_array_int, sizeof(int), cmp);
    //quick_sort(array_int, len_array_int, sizeof(int), cmp);
    //heap_sort(array_int, len_array_int, sizeof(int), cmp);
    delta = omp_get_wtime() - start;

    //<editor-fold desc="Check if the array is sorted">
    int issort = issorted(array_int, len_array_int, sizeof(int32_t), cmp);
    if (issort) {
        printf("array is sorted in %.4f sec.\n", delta);
    } else {
        printf("array is not sorted\n");
    }
    //</editor-fold>

    //<editor-fold desc="Display contents (array_int)">
    if (len_array_int <= 128) {
        for (size_t i = 0; i < len_array_int; ++i) {
            printf("%3d, ", array_int[i]);
            if ((i+1)% 16 == 0) printf("\n");
        }
        printf("\n");
    }
    //</editor-fold>

    free(array_int);
}

