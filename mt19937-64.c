#include "mt19937-64.h"

#define NN 312
#define MM 156
#define MATRIX_A 0xB5026F5AA96619E9ULL
#define UM 0xFFFFFFFF80000000ULL    /* Most  significant 33 bits */
#define LM 0x7FFFFFFFULL            /* Least significant 31 bits */


/* The array for the state vector */
static uint64_t mt[NN];


/* mti==NN+1 means mt[NN] is not initialized */
static int mti=NN+1;


void
mt_seed(uint64_t seed) {
    mt[0] = seed;
    for (mti=1; mti<NN; mti++)
    {
        mt[mti] = (6364136223846793005ULL * (mt[mti-1] ^ (mt[mti-1] >> 62)) + mti);
    }

}


uint64_t
mt_rand_uint64(void)
{
    int i;
    uint64_t x;
    static uint64_t mag01[2]={0ULL, MATRIX_A};

    if (mti >= NN) /* generate NN words at one time */
    {

        /* if mt_seed() has not been called, */
        /* a default initial seed is used     */
        if (mti == NN+1) {
            mt_seed(5489ULL);
        }

        for (i = 0; i < NN - MM; ++i)
        {
            x = (mt[i]&UM)|(mt[i+1]&LM);
            mt[i] = mt[i + MM] ^ (x>>1) ^ mag01[(int)(x&1ULL)];
        }

        for (; i < NN - 1; ++i)
        {
            x = (mt[i]&UM)|(mt[i+1]&LM);
            mt[i] = mt[i+(MM-NN)] ^ (x>>1) ^ mag01[(int)(x&1ULL)];
        }

        x = (mt[NN-1]&UM)|(mt[0]&LM);
        mt[NN-1] = mt[MM-1] ^ (x>>1) ^ mag01[(int)(x&1ULL)];

        mti = 0;
    }

    x = mt[mti++];

    x ^= (x >> 29) & 0x5555555555555555ULL;
    x ^= (x << 17) & 0x71D67FFFEDA60000ULL;
    x ^= (x << 37) & 0xFFF7EEE000000000ULL;
    x ^= (x >> 43);

    return x;
}

int64_t
mt_rand_int63(void)
{
    return (int64_t)(mt_rand_uint64() >> 1);
}


double
mt_rand_double_1(void)
{
    return (mt_rand_uint64() >> 11) * (1.0/9007199254740991.0);
}


double
mt_rand_double_2(void)
{
    return (mt_rand_uint64() >> 11) * (1.0/9007199254740992.0);
}


double
mt_rand_double_3(void)
{
    return ((mt_rand_uint64() >> 12) + 0.5) * (1.0/4503599627370496.0);
}

