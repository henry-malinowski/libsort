#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <memory.h>

#include "tests_partition.h"
#include "array_generators.h"
#include "../mt19937-64.h"
#include "../include/partition.h"
#include "../include/comparisons_floats.h"
#include "../include/comparisons_ints.h"

typedef enum {
    INT_16 = 0,
    INT_32 = 1,
    INT_64 = 2,
    FP32   = 3,
    FP64   = 4,
}
ARRAY_TYPE;

char* array_type_names[] = {"INT_16", "INT_32", "INT_64", "FP32", "FP64"};

void
partition_lomuto_tests(void)
{
    FILE* old_stdout = stdout;
    stdout = fopen("/dev/null", "w+");

    #ifdef TESTS_VERBOSE
        stdout = old_stdout;
    #endif

    // Track the number of tests ran and report to caller on stdout.
    uint32_t total_tests = 0;
    uint32_t passes = 0;

    char** array_type_name;

    bool malloc_failed = false;
    void* array = NULL;
    cmp_func less_than = NULL; // This is set at the same time the element size is picked

    ARRAY_TYPE array_type;

    uint64_t seed = 0;
    size_t array_nmbers = 0;
    size_t type_size = 0;

    void* pivot = NULL;
    int is_part;

    unsigned driverrand = (unsigned) time(NULL);
    printf("\nseed of the driver rand was %u\n", driverrand);
    srand(driverrand);

    for (uint32_t i = 0; i < PARTITION_TESTS*5; ++i) {
        /* Select random array type and set string for user output later */
        array_type = (ARRAY_TYPE) (rand() % 5); // 5 is the number of ARRAY_TYPEs
        array_type_name = &array_type_names[(int)array_type];

        array_nmbers = (size_t) 3 + (rand() % 1000);

        //<editor-fold desc="Select element size, pick less_than, and allocate array">
        switch (array_type) {
            case INT_16:
                type_size = sizeof(int16_t);
                less_than = &cmp_less_int16;
                break;
            case INT_32:
                type_size = sizeof(int32_t);
                less_than = &cmp_less_int32;
                break;
            case INT_64:
                type_size = sizeof(int64_t);
                less_than = &cmp_less_int64;
                break;
            case FP32:
                type_size = sizeof(float);
                less_than = &cmp_less_fp32;
                break;
            case FP64:
                type_size = sizeof(double);
                less_than = &cmp_less_fp64;
                break;
        }

        array = calloc(array_nmbers, type_size);
        //</editor-fold>

        // check for malloc failure
        if (array == NULL) {
            malloc_failed = true;
            break;
        }

        //<editor-fold desc="fill the array and store seed used">
        switch (array_type) {
            case INT_16:
                seed = array_fill_int16_t(array, array_nmbers, seed_prng, mt_rand_uint64);
                break;
            case INT_32:
                seed = array_fill_int32_t(array, array_nmbers, seed_prng, mt_rand_uint64);
                break;
            case INT_64:
                seed = array_fill_int64_t(array, array_nmbers, seed_prng, mt_rand_uint64);
                break;
            case FP32:
                seed = array_fill_fp32(array, array_nmbers, seed_prng, rand_float);
                break;
            case FP64:
                seed = array_fill_fp64(array, array_nmbers, seed_prng, rand_double);
                break;
        }
        //</editor-fold>


        pivot = partition_lomuto(array, array_nmbers, type_size, less_than);
        is_part = partition_verify(array, array_nmbers, type_size, less_than, pivot);

        free(array);

        if (is_part) {
            fprintf(stdout, "Array succeed in partitioning\n");
            ++total_tests;
            ++passes;
        } else {
            fprintf(stdout, "Array failed to partition\n");
            ++total_tests;
        }

        fprintf(stdout,
                "  ├seed: %zu\n"
                "  ├size: %zu\n"
                "  └type: %s\n\n",
                seed, array_nmbers, *array_type_name
        );
    }

    // reset stdout to normal mode.
    fflush(stdout);
    fclose(stdout);
    stdout = old_stdout;

    fprintf(stdout,
            "Totals\n"
            "  ├tests:  %u\n"
            "  ├passes: %u\n"
            "  └fails:  %u\n",
            total_tests, passes, total_tests-passes
    );
    if (malloc_failed) {
        fprintf(stderr, "fatal: calloc failed to allocate %zu bytes\n", array_nmbers*type_size);
    }
}