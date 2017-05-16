/**
 * @file
 * A C-program for MT19937-64 (2004-09-29 version).
 * Coded by Takuji Nishimura and Makoto Matsumoto.
 *
 * This is a 64-bit version of Mersenne Twister pseudorandom number
 * generator.
 *
 * Before using, initialize the state by using mt_seed(seed)
 * or init_by_array64(init_key, key_length).
 *
 * References:
 * <p>
 * \cite Matsumoto_Nishimura
 * M. Matsumoto and T. Nishimura,
 *      ``Mersenne Twister: a 623-dimensionally equidistributed
 *      uniform pseudorandom number generator''
 * <p>
 * \cite tables_mersenne_twisters
 * T. Nishimura, ``Tables of 64-bit Mersenne Twisters''
 *      ACM Transactions on Modeling and
 *      Computer Simulation 10. (2000) 348--357.
 * <p>
 * \cite tables_mersenne_twisters_2
 * ACM Transactions on Modeling and
 *      Computer Simulation 8. (Jan. 1998) 3--30.
 *
 * Any feedback is very welcome.
 * http://www.math.hiroshima-u.ac.jp/~m-mat/MT/emt.html
 *
 * email: m-mat@math.sci.hiroshima-u.ac.jp
 *
 * @copyright (C) 2004, Makoto Matsumoto and Takuji Nishimura, All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *  notice, this list of conditions and the following disclaimer in the
 *  documentation and/or other materials provided with the distribution.
 *
 * 3. The names of its contributors may not be used to endorse or promote
 *  products derived from this software without specific prior written
 *  permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdint.h>

#ifndef SHUFFLE_LIB_MT19937_64_H
#define SHUFFLE_LIB_MT19937_64_H

/**
 * Seed this instance of the Mersenne Twister.
 * @param seed An unsigned 64 bit integer to be used at the seed.
 */
void mt_seed(uint64_t seed);

/**
 * Generates a random number on [0, 2^64-1]-interval.
 * @returns A random number on the interval \f$ [0, 2^{64}-1]\f$.
 */
uint64_t mt_rand_uint64(void);


/**
 * Generates a random number on [0, 2^63-1]-interval.
 * @returns A random number on the interval \f$ [0, 2^{63}-1]\f$.
 */
int64_t mt_rand_int63(void);


/**
 * Generates a random number on [0, 1]-real-interval.
 *
 * @returns A double on the interval of \f$[0, 1] \f$
 */
double mt_rand_double_1(void);


/**
 * Generates a random number on [0, 1)-real-interval.
 * @returns A double on the interval of \f$ [0, 1) \f$
 */
double mt_rand_double_2(void);


/**
 * Generates a random number on (0, 1)-real-interval.
 * @returns A double on the interval of \f$ (0, 1) \f$
 */
double mt_rand_double_3(void);

#endif //SHUFFLE_LIB_MT19937_64_H
