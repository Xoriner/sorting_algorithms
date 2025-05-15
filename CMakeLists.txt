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
        sorting/shellsort.h)
