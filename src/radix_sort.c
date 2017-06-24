#include "../include/radix_sort.h"
#include <stdint.h>

#define SWAP(TYPE)              \
    do {                        \
        TYPE temp = *(TYPE*)a;  \
        *(TYPE*)a = *(TYPE*)b;  \
        *(TYPE*)b = temp;       \
    } while(0)

#define RADIX_BASE 16

/**
 * @brief The type of a swap function.
 * This ensure that ints are not swapped char-by-char, but by their data type;
 */
typedef void(*swap_func_t) (void*, void*);

/**
 * @brief Assists in pointing to the correct swap function from the jump table.
 */
typedef enum {
    INT8  = 1, /**< Indicates the use of a 1 byte or 8-bit integer type.  */
    INT16 = 2, /**< Indicates the use of a 2 byte or 16-bit integer type. */
    INT32 = 4, /**< Indicates the use of a 4 byte or 32-bit integer type. */
    INT64 = 8  /**< Indicates the use of a 6 byte or 64-bit integer type. */
} SWAP_SIZE;

swap_func_t swap_functions[] = {NULL,
                                swap_int8, swap_int16, NULL, swap_int32,
                                NULL     , NULL,       NULL, swap_int64};

void
radix_sort_lsd(void *base, size_t nmemb, size_t size,
               unsigned (*mod)(const void *, unsigned base))
{
    // Matches the swap function to a pointer in the swap_functions jump-table.
    //swap_func_t swap = swap_functions[size]; // swap may equal NULL
    swap_func_t swap;

    /* first: A pointer to the first element in the array
     *  last: A pointer to the last element in the array.
     */
    char* const first = (char*) base;
    char* const last = first + (nmemb-1)*size;

    // csort: array for performing count-sort
    size_t* csort_array = calloc(size, RADIX_BASE);
    if (csort_array == NULL) {
        return;
    }

    free(csort_array);
}


void
swap_int8(void* a, void* b)
{
    /* replaced with macro...
        int8_t temp = *(int8_t*) a;
        *(int8_t*)a = *(int8_t*)b;
        *(int8_t*)b = temp;
    */

    SWAP(int8_t);
}


void
swap_int16(void* a, void* b)
{
    SWAP(int16_t);
}


void
swap_int32(void* a, void* b)
{
    SWAP(int32_t);
}


void
swap_int64(void* a, void* b)
{
    SWAP(int64_t);
}

