#include <stddef.h>
#include <stdint.h>

#ifndef TESTS_PARTITION_H
#define TESTS_PARTITION_H

uint64_t
array_fill_int16_t(int16_t* a, size_t nmemb, void (*rseed)(uint64_t),
                   uint64_t (*rand_func)(void));


uint64_t
array_fill_int32_t(int32_t* a, size_t nmemb, void (*rseed)(uint64_t),
                   uint64_t (*rand_func)(void));


uint64_t
array_fill_int64_t(int64_t* a, size_t nmemb, void (*rseed)(uint64_t),
                   uint64_t (*rand_func)(void));


/**
 * Fills an array with random floating point values.
 * @param a          [in,out] The array to be filled.
 * @param nmemb       [in] The number of elements in the array.
 * @param rseed      [in] A function that sees \p rand_float
 * @param rand_float [in] A function that returns random floating point values.
 * @return The seed that the PNGR was seeded with.
 */
uint64_t array_fill_fp32(float* a, size_t nmemb, void (*rseed)(uint64_t),
                         float (*rand_func)(void));


/**
 * Fills an array with random double-presicion floating point values.
 * @param a          [in,out] The array to be filled.
 * @param nmemb       [in] The number of elements in the array.
 * @param rseed      [in] A function that sees \p rand_float
 * @param rand_float [in] A function that returns random floating point values.
 * @return The seed that the PNGR was seeded with.
 */
uint64_t array_fill_fp64(double* a, size_t nmemb, void (*rseed)(uint64_t),
                         double (*rand_func)(void));

/**
 * Seeds the PRNG.
 * @param seed The number to seed the PRNG with.
 */
void seed_prng(uint64_t seed);


/* Returns a uint64_t that contains to 32-bit numbers less than 30.
 */
uint64_t little_rand(void);


/**
 * Uses mt_mt_rand_double_1 to return a pseudo-random number on the
 *  real-interval\f$[0,1000]\f$.
 * @return A number between 0 and 1000 inclusive.
 */
float rand_float(void);


/**
 * Uses mt_mt_rand_double_1 to return a pseudo-random number on the
 *  real-interval\f$[0,1000]\f$.
 * @return A double between 0 and 1000 inclusive.
 */
double rand_double(void);

#endif /* TESTS_PARTITION_H */
