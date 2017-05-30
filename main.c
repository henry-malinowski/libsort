#include <stdio.h>
#include <omp.h>
#include <stdint.h>
#include <stdlib.h>

#include "mt19937-64.h"

#include "./include/comparisons_ints.h"
#include "include/merge_sort.h"

#define ARRAY_SIZE(x) (sizeof(x)/(sizeof((x)[0])))

union u_seed {
    double d;
    uint64_t i;
};


int main(void) {
    unsigned int array_int32[10] = {
            1, 3, 4, 7, 8, 10,
            2, 5, 6, 9
    };
    const size_t array_int32_size = ARRAY_SIZE(array_int32);

    __compar_fn_t cmp = &cmp_lt_uint;

    //<editor-fold desc="Print array (pre-merge)">
    printf("Array pre-merge:\n");
    for (int i = 0; i < array_int32_size; ++i) {
        printf("%d ", array_int32[i]);
        if (i == (array_int32_size/2 - 1)) printf("\n");
    } printf("\n\n");
    //</editor-fold>

    // merge the first half with the second half
    merge(array_int32, 6, 4, sizeof(unsigned int), cmp);


    //<editor-fold desc="Print array (post-merge)">
    printf("Array post-merge:\n");
    for (int i = 0; i < array_int32_size; ++i) {
        printf("%d ", array_int32[i]);
        if (i == (array_int32_size/2 - 1)) printf("\n");
    } printf("\n");
    //</editor-fold>
}

