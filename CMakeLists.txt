cmake_minimum_required(VERSION 3.7)
project(C_Sorting_Lib)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-fopenmp -lgmp") #  -lgmp for GnuMultiplePrecision library

set(GCC_COVERAGE_COMPILE_FLAGS "-O0" "-Wall" "-Wno-unused-variable" "-pedantic" "-g" "-fsanitize=leak" "-fstrict-overflow")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

set(SOURCE_FILES main.c shuffle.c shuffle.h mt19937-64.c mt19937-64.h src/insertion_sort.c include/insertion_sort.h src/issorted.c include/issorted.h src/selection_sort.c include/selection_sort.h src/find_min.c include/find_min.h src/network_sorting.c include/network_sorting.h src/bubble_sort.c include/bubble_sort.h src/quick_sort.c include/quick_sort.h src/partition.c include/partition.h tests/array_generators.c tests/array_generators.h tests/tests_partition.c tests/tests_partition.h src/comparisons_floats.c include/comparisons_floats.h src/comparisons_ints.c include/comparisons_ints.h src/shell_sort.c include/shell_sort.h src/comparisons_stdint.c include/comparisons_stdint.h src/merge_sort.c include/merge_sort.h src/heap_sort.c include/heap_sort.h src/swap.c include/swap.h src/radix_sort.c include/radix_sort.h src/comparisons_gmp.c include/comparisons_gmp.h src/gnome_sort.c include/gnome_sort.h)
add_executable(C_Sorting_Lib ${SOURCE_FILES})