#ifndef QUICKSORT_H
#define QUICKSORT_H

template<typename T>
void quick_sort_recursion(T* arr, int low, int high); // declaration of functions

template<typename T>
void quick_sort_left_pivot(T* arr, int low, int high);

template<typename T>
void quick_sort_right_pivot(T* arr, int low, int high);

template<typename T>
void quick_sort_middle_pivot(T* arr, int low, int high);

template<typename T>
void quick_sort_random_pivot(T* arr, int low, int high);

#include "quicksort.tpp" // implementation

#endif // QUICKSORT_H