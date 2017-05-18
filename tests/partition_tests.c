#include "partition_tests.h"
#include "../mt19937-64.h"
#include <omp.h>

typedef union u_time_seed{
    double time;
    uint64_t d;
} time_seed;


/**
 * @brief Union that allows for the easy extraction of signed 32 bit values from
 *  an unsigned 64 bit source without using bitwise shifts.
 */
typedef union u_rand_int32_t{
    uint64_t num;
    int32_t a[2];
} rand_int32_t;

/**
 * @brief Union that allows for the easy extraction of signed 16 bit values from
 *  an unsigned 64 bit source without using bitwise shifts.
 */
typedef union u_rand_int16_t{
    uint64_t num;
    int16_t a[4];
} rand_int16_t;


uint64_t
array_fill_fp32(float* a, size_t size, void (*rseed)(uint64_t),
                float(*rand_float)(void))
{
    /* Seed the PRNG */
    time_seed t;
    t.time = omp_get_wtime();
    rseed(t.d);

    /* Fill the array with random floats */
    for (size_t i = 0; i < size; ++i) {
        a[i] = rand_float();
    }

    /* Return the seed in integer form */
    return t.d;
}


uint64_t
array_fill_fp64(double* a, size_t size, void (*rseed)(uint64_t),
                double (*rand_double)(void))
{
    /* Seed the PRNG */
    time_seed t;
    t.time = omp_get_wtime();
    rseed(t.d);

    /* Fill the array with random floats */
    for (size_t i = 0; i < size; ++i) {
        a[i] = rand_double();
    }

    /* Return the seed in integer form */
    return t.d;
}


uint64_t
array_fill_int16_t(int32_t* a, size_t size, void (*rseed)(uint64_t),
                   uint64_t (*rand_uint64_t)(void))
{
    rand_int32_t nums;

    size_t i = 0;
    size_t repeat = size / 4;
    size_t remaining = size % 4;

    while (repeat--)
    {
        // Generate batch of random numbers
        nums.num = rand_uint64_t();

        a[i + 0] = nums.a[0];
        a[i + 1] = nums.a[1];
        a[i + 2] = nums.a[2];
        a[i + 3] = nums.a[3];
        i += 4;
    }

    // handle remaining cases
    if (remaining != 0) {
        nums.num = rand_uint64_t();
        switch (remaining) {
            case 3: a[i+3] = nums.a[3];
            case 2: a[i+3] = nums.a[2];
            case 1: a[i+3] = nums.a[1];
            default:;
        }
    }
}


uint64_t
array_fill_int32_t(int32_t* a, size_t size, void (*rseed)(uint64_t),
                   uint64_t (*rand_uint64_t)(void))
{
    rand_int32_t nums;

    size_t i = 0;
    size_t repeat = size / 2;
    size_t remaining = size % 2;

    while (repeat--)
    {
        // Generate batch of random numbers
        nums.num = rand_uint64_t();

        a[i + 0] = nums.a[0];
        a[i + 1] = nums.a[1];
        i += 2;
    }

    // handle remaining cases
    if (remaining == 1) {
        nums.num = rand_uint64_t();
        a[i] = nums.a[0] ^ nums.a[1];
    }
}


void
seed_prng(uint64_t seed) {
    mt_seed(seed);
}


float
rand_float(void) {
    return (float)(mt_rand_double_1() * 1000);
}


double
rand_double(void) {
    return (mt_rand_double_1() * 1000);
}