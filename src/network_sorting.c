/**
 * A C source file that includes a type agnostic network sorting algorithms.
 *
 * @copyright (C) 2017 Henry Malinowski <malinowski.henry@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "../include/network_sorting.h"

/**
 * @brief Byte-wise swap two items of size \p size.
 * This code is borrowed straight from the GCC qsort implementation of SWAP.
 */
#define SWAP(a, b, size)                \
    do                                  \
    {                                   \
        size_t __size = (size);			\
        char *__a = (a), *__b = (b);    \
        do                              \
        {                               \
            char __tmp = *__a;          \
            *__a++ = *__b;              \
            *__b++ = __tmp;             \
        } while (--__size > 0);         \
    } while (0)                         \


void
network_sort_4_wire(void* base, size_t nmemb, size_t size,
                    int (*cmp)(const void*, const void*))
{
    if (nmemb != 4) return;

    /* initialize pointers to the 4 wires of the network */
    char* a = (char*) base;
    char* b = a + size;
    char* c = b + size;
    char* d = c + size;

    /* Run through sorting network */
    if (cmp(a, b) > 0) SWAP(a, b, size);
    if (cmp(c, d) > 0) SWAP(c, d, size);
    if (cmp(a, c) > 0) SWAP(a, c, size);
    if (cmp(b, d) > 0) SWAP(b, d, size);
    if (cmp(b, c) > 0) SWAP(b, c, size);
}


void network_sort_5_wire(void* base, size_t nmemb, size_t size,
                         int (*cmp)(const void*, const void*))
{
    if (nmemb != 5) return;

    /* initialize pointers to the 5 wires of the network */
    char* a = (char*) base;        /* 0 */
    char* b = a + size;            /* 1 */
    char* c = b + size;            /* 2 */
    char* d = c + size;            /* 3 */
    char* e = d + size;            /* 4 */

    /* Run through sorting network */
    /* Phase 1: [0, 1], [3, 4] */
    if (cmp(a, b) > 0) SWAP(a, b, size);
    if (cmp(d, e) > 0) SWAP(d, e, size);

    /* Phase 2: [2, 4] */
    if (cmp(c, e) > 0) SWAP(c, e, size);

    /* Phase 3: [2, 3], [1, 4] */
    if (cmp(c, d) > 0) SWAP(c, d, size);
    if (cmp(b, e) > 0) SWAP(b, a, size);

    /* Phase 4: [0, 3] */
    if (cmp(a, d) > 0) SWAP(a, d, size);

    /* Phase 5: [0, 2], [1, 3] */
    if (cmp(a, c) > 0) SWAP(a, c, size);
    if (cmp(b, d) > 0) SWAP(b, d, size);

    /* Phase 6: [1, 2] */
    if (cmp(b, c) > 0) SWAP(b, c, size);
}


void
network_sort_6_wire(void* base, size_t nmemb, size_t size,
                    int (*cmp)(const void*, const void*))
{
    if (nmemb != 6) return;

    /* initialize pointers to the 8 wires of the network */
    char* a = (char*) base;        /* 0 */
    char* b = a + size;            /* 1 */
    char* c = b + size;            /* 2 */
    char* d = c + size;            /* 3 */
    char* e = d + size;            /* 4 */
    char* f = e + size;            /* 5 */

    /* Run through sorting network      */
    /* Phase 1: [1, 2], [4, 5]          */
    if (cmp(b, c) > 0) SWAP(b, c, size);
    if (cmp(e, f) > 0) SWAP(e, f, size);

    /* Phase 2: [0, 2], [3, 5]          */
    if (cmp(a, c) > 0) SWAP(a, c, size);
    if (cmp(d, f) > 0) SWAP(d, f, size);

    /* Phase 3: [0, 1], [3, 4], [2, 5]  */
    if (cmp(a, b) > 0) SWAP(a, b, size);
    if (cmp(d, e) > 0) SWAP(d, e, size);
    if (cmp(c, f) > 0) SWAP(c, f, size);

    /* Phase 4: [0, 3], [1, 4]          */
    if (cmp(a, d) > 0) SWAP(a, d, size);
    if (cmp(b, e) > 0) SWAP(b, e, size);

    /* Phase 5: [2, 4], [1, 3]          */
    if (cmp(c, e) > 0) SWAP(c, e, size);
    if (cmp(b, d) > 0) SWAP(b, d, size);

    /* Phase 6: [2, 3]                  */
    if (cmp(c, d) > 0) SWAP(c, d, size);
}


void
network_sort_8_wire(void* base, size_t nmemb, size_t size,
                    int (*cmp)(const void*, const void*))
{
    if (nmemb != 8) return;

    /* initialize pointers to the 8 wires of the network */
    char* a = base;
    char* b = a + size;
    char* c = b + size;
    char* d = c + size;
    char* e = d + size;
    char* f = e + size;
    char* g = f + size;
    char* h = g + size;

    /* Run through sorting network */
    if (cmp(a, e) > 0) SWAP(a, e, size);
    if (cmp(b, f) > 0) SWAP(b, f, size);
    if (cmp(c, g) > 0) SWAP(c, g, size);
    if (cmp(d, h) > 0) SWAP(d, h, size);
    if (cmp(a, c) > 0) SWAP(a, c, size);
    if (cmp(b, d) > 0) SWAP(b, d, size);
    if (cmp(e, g) > 0) SWAP(e, g, size);
    if (cmp(a, b) > 0) SWAP(a, b, size);
    if (cmp(c, e) > 0) SWAP(c, e, size);
    if (cmp(f, h) > 0) SWAP(f, h, size);
    if (cmp(d, f) > 0) SWAP(d, f, size);
    if (cmp(g, h) > 0) SWAP(g, h, size);
    if (cmp(c, d) > 0) SWAP(c, d, size);
    if (cmp(e, f) > 0) SWAP(e, f, size);
    if (cmp(b, e) > 0) SWAP(b, e, size);
    if (cmp(b, c) > 0) SWAP(b, c, size);
    if (cmp(d, g) > 0) SWAP(d, g, size);
    if (cmp(d, e) > 0) SWAP(d, e, size);
    if (cmp(f, g) > 0) SWAP(f, g, size);
}
