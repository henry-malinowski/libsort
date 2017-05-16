cmake_minimum_required(VERSION 3.7)
project(C_Sorting_Lib)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-fopenmp")

set(SOURCE_FILES main.c shuffle.c shuffle.h mt19937-64.c mt19937-64.h src/insertion_sort.c include/insertion_sort.h src/issorted.c include/issorted.h src/selection_sort.c include/selection_sort.h src/find_min.c include/find_min.h src/network_sorting.c include/network_sorting.h src/bubble_sort.c include/bubble_sort.h)
add_executable(C_Sorting_Lib ${SOURCE_FILES})