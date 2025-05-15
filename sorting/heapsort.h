#ifndef HEAPSORT_H
#define HEAPSORT_H

template<typename T>
void heapify(T* arr, int n, int i);

template<typename T>
void heap_sort(T* arr, int n);

#include "heapsort.tpp"

#endif //HEAPSORT_H
