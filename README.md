# libsort
A collection of type agnostic sorting algorithms.

The ultimate goal of this project is to make a collocation of comparative and non-comparative sorting algorithms in a type agnostic fashion.
This would allow for sorts be be called as...

```c
    insertion_sort(array, ARRAY_SIZE(array), sizeof(array[0]), cmpfunc);
```

This would follow the prototype that the C standard outlines for [`qsort(3)`](https://linux.die.net/man/3/qsort).
The one exception to this being the non-comparative sorts.
For example, radix sort will require `unsigned mod(void* num, unsigned base)`, where `num` is a pointer to some unsigned integer type.

### Comparative sorts
* [Bubble Sort](https://en.wikipedia.org/wiki/Bubble_sort)
* [Gnome Sort](https://en.wikipedia.org/wiki/Gnome_sort)
* [Shell Sort](https://en.wikipedia.org/wiki/Shellsort)
* [Selection Sort](https://en.wikipedia.org/wiki/Selection_sort)
* [Insertion Sort](https://en.wikipedia.org/wiki/Insertion_sort)
* [Quick Sort](https://en.wikipedia.org/wiki/Quicksort)
* [Merge Sort](https://en.wikipedia.org/wiki/Merge_sort)
* [Heap Sort](https://en.wikipedia.org/wiki/Heapsort)
* [Sorting networks of sizes 2 to 8 wires](https://en.wikipedia.org/wiki/Sorting_network)

### Non-Comparative sorts
* [Counting sort](https://en.wikipedia.org/wiki/Counting_sort)
* [Radix Sort (LSD)](https://en.wikipedia.org/wiki/Radix_sort)
* [Radix Sort (MSD)](https://en.wikipedia.org/wiki/Radix_sort#Most_significant_digit_radix_sorts)
* [Bucket Sort](https://en.wikipedia.org/wiki/Bucket_sort)

Behavior for sorting non-integer types would be undefined, but the functions would support sorting of any integer type.

### Assisting functions
* Verify sort
* [Lomuto's partition](https://en.wikipedia.org/wiki/Quicksort#Lomuto_partition_scheme)
* [Hoare's partition](https://en.wikipedia.org/wiki/Quicksort#Hoare_partition_scheme)
* Verify partition
* [Array merge](https://en.wikipedia.org/wiki/Merge_algorithm#Merging_two_lists)
* In-place array merge
* Heapify & Shift-down
* [PCG PRNG](http://www.pcg-random.org/)

This library will also have will also come with some testing functions to debug and verify the result of the sorting and partitioning functions.
To achieve this goal the library will also come with some nice generator functions, so that one can quickly fill arrays with random data.
These will also be easily extensible due to the extensive use of function pointers in the generator functions.

At the moment, a 64-bit implementation of the Mersenne Twister is used.
For quickly testing all the sorts, it is too slow for the generation of the arrays and dose not provide any special quality of numbers that justify its slowness.
For this reason, a migration will be made to a C implementation of the PCG family of pseudo-random number generators.
