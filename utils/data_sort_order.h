#ifndef DATA_SORT_ORDER_H
#define DATA_SORT_ORDER_H

#include "../sorting/quicksort.h"
#include <fstream>
#include <string>
enum class SortType {
    Insertion,
    QuickMiddle,
    QuickLeft,
    QuickRight,
    QuickRandom,
    Heap,
    Shell,
    ShellCiura
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

template<typename T>
void sort_prefix(T* arr, int size, double fraction);

template<typename T>
void reverse_sort(T* arr, int size);

template<typename T>
T* read_file(const std::string& filename, int& sizeOut);

#include "data_sort_order.tpp"

#endif //DATA_SORT_ORDER_H
