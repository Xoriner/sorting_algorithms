#ifndef DATA_SORT_ORDER_H
#define DATA_SORT_ORDER_H

enum class SortType {
    Insertion,
    Quick,
    Heap
};

enum class DataOrder {
    Random,
    Sorted,
    Reversed,
    Partial33,
    Partial66
};

template<typename T>
void fill_random(T* arr, int size);

template<typename T>
void fill_data(T* arr, int size, DataOrder order);

#include "data_sort_order.tpp"

#endif //DATA_SORT_ORDER_H
