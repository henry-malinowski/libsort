# libsort
A collection of type agnostic sorting algorithms.

The ultimate goal of this project is to make a collocation of comparative 
and non-comparative sorting algorithms in a type agnostic fashion.

Some of the comparative algorithms would be...
* [Bubble Sort](https://en.wikipedia.org/wiki/Bubble_sort)
* [Shell Sort](https://en.wikipedia.org/wiki/Shellsort)
* [Selection Sort](https://en.wikipedia.org/wiki/Selection_sort)
* [Insertion Sort](https://en.wikipedia.org/wiki/Insertion_sort)
* [Quick Sort](https://en.wikipedia.org/wiki/Quicksort)
* [Merge Sort](https://en.wikipedia.org/wiki/Merge_sort)
* [Sorting networks of sizes 2 to 8 wires](https://en.wikipedia.org/wiki/Sorting_network)

Some of the non-comparative algorithms would be...
* [Counting sort](https://en.wikipedia.org/wiki/Counting_sort)
* [Radix Sort (LSD)](https://en.wikipedia.org/wiki/Radix_sort)
* [Radix Sort (MSD)](https://en.wikipedia.org/wiki/Radix_sort#Most_significant_digit_radix_sorts)
* [Bucket Sort](https://en.wikipedia.org/wiki/Bucket_sort)

Some non-sorting functions would also be included to either
assist in sorting, and as example of good or bad algorithms.
* [Lomuto's partition](https://en.wikipedia.org/wiki/Quicksort#Lomuto_partition_scheme)
* [Hoare's partition](https://en.wikipedia.org/wiki/Quicksort#Hoare_partition_scheme)
* Verify partition
* [Array merge](https://en.wikipedia.org/wiki/Merge_algorithm#Merging_two_lists)
* In-place array merge

Behavior for sorting non-integer types would be undefined, but the functions
 would support sorting of any integer type.
