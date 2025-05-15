#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "data_sort_order.h"
#include "print_check_array.h"
#include "../sorting/insertionsort.h"
#include "../sorting/heapsort.h"
#include "../sorting/quicksort.h"
#include "../sorting/shellsort.h"

template<typename T>
void benchmark_algorithms(int size, SortType algorithm, DataOrder dataOrder);

#include "benchmark.tpp"
#endif //BENCHMARK_H
