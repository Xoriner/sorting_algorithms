cmake_minimum_required(VERSION 3.30)
project(ProjektAiZo)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProjektAiZo main.cpp
        sorting/quicksort.tpp
        sorting/quicksort.h
        sorting/insertionsort.tpp
        sorting/insertionsort.h
        sorting/heapsort.tpp
        sorting/heapsort.h
        sorting/shellsort.tpp
        sorting/shellsort.h
        utils/benchmark.tpp
        utils/benchmark.h
        utils/data_sort_order.tpp
        utils/data_sort_order.h
        utils/print_check_array.tpp
        utils/print_check_array.h)
